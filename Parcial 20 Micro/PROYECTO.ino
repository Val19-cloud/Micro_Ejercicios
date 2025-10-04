#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <EEPROM.h>
#include <SPI.h>
#include <MFRC522.h>
#include "RTClib.h"
#include <WiFiClientSecure.h>

#define SS_PIN 5
#define RST_PIN 27
#define BUTTON_PIN 15

MFRC522 rfid(SS_PIN, RST_PIN);
RTC_DS3231 rtc;

const char *ssid = "iPhone";
const char *password = "Valen9875";

const char *mqtt_broker = "05aca28dec0b41c7ba187fee8b90c004.s1.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char *mqtt_user = "Valen";
const char *mqtt_pass = "Valen9875";

WiFiClientSecure espClient;
PubSubClient client(espClient);

volatile bool registroPendiente = false;
#define EEPROM_SIZE 512


String getHora() {
  DateTime now = rtc.now();
  char buffer[30];
  sprintf(buffer, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  return String(buffer);
}


void saveUID(String uid) {
  for (int i = 0; i < EEPROM_SIZE; i += 20) {
    if (EEPROM.read(i) == 0xFF) {
      for (int j = 0; j < uid.length(); j++) EEPROM.write(i + j, uid[j]);
      EEPROM.write(i + uid.length(), '\0');
      EEPROM.commit();
      break;
    }
  }
}

bool uidExists(String uid) {
  for (int i = 0; i < EEPROM_SIZE; i += 20) {
    if (EEPROM.read(i) != 0xFF) {
      String saved = "";
      for (int j = 0; j < 20; j++) {
        char c = EEPROM.read(i + j);
        if (c == '\0') break;
        saved += c;
      }
      if (saved == uid) return true;
    }
  }
  return false;
}

void deleteUID(String uid) {
  for (int i = 0; i < EEPROM_SIZE; i += 20) {
    if (EEPROM.read(i) != 0xFF) {
      String saved = "";
      for (int j = 0; j < 20; j++) {
        char c = EEPROM.read(i + j);
        if (c == '\0') break;
        saved += c;
      }
      if (saved == uid) {
        for (int j = 0; j < 20; j++) EEPROM.write(i + j, 0xFF);
        EEPROM.commit();
        client.publish("acceso/registro", ("Tarjeta eliminada: " + uid + " - Hora: " + getHora()).c_str());
        return;
      }
    }
  }
  client.publish("acceso/registro", "UID no encontrado");
}


void IRAM_ATTR registrarISR() {
  registroPendiente = true;
}


void callback(char* topic, byte* payload, unsigned int length) {
  String msg = "";
  for (unsigned int i = 0; i < length; i++) msg += (char)payload[i];

  if (msg.startsWith("ELIMINAR:")) {
    String uid = msg.substring(9);
    deleteUID(uid);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Conectando al broker MQTT...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println("Conectado al broker MQTT.");
      client.subscribe("acceso/control");
    } else {
      Serial.println("Fallo en conexión, reintentando...");
      delay(2000);
    }
  }
}


void taskRFID(void *pvParameters) {
  static bool mostrarRegistro = false;
  for (;;) {

     if (registroPendiente && !mostrarRegistro) {
      client.publish("acceso/registro", "Modo registro activado, pase de nuevo la tarjeta");
      mostrarRegistro = true;
    }
    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
      String uid = "";
      for (byte i = 0; i < rfid.uid.size; i++) {
        uid += String(rfid.uid.uidByte[i], HEX);
      }

      if (registroPendiente) {
        registroPendiente = false;
        mostrarRegistro = false;
        saveUID(uid);
        String msg = "Nueva tarjeta registrada: " + uid + " - Hora: " + getHora();
        client.publish("acceso/registro", msg.c_str());
      } else {
        if (uidExists(uid)) {
          String msg = "ACCESO PERMITIDO - UID: " + uid + " - Hora: " + getHora();
          client.publish("acceso/estado", msg.c_str());
        } else {
          String msg = "ACCESO DENEGADO - UID: " + uid + " - Hora: " + getHora();
          client.publish("acceso/estado", msg.c_str());
        }
      }
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
    }
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void taskMQTT(void *pvParameters) {
  for (;;) {
    if (!client.connected()) reconnect();
    client.loop();
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void taskRTC(void *pvParameters) {
  for (;;) {
    String hora = getHora();
    client.publish("acceso/tiempo", hora.c_str());
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);

  Serial.println("Conectando al WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado al WiFi.");

  espClient.setInsecure();
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
 
  SPI.begin();
  rfid.PCD_Init();
  rtc.begin();

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), registrarISR, FALLING);

  xTaskCreatePinnedToCore(taskRFID, "TaskRFID", 4096, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskMQTT, "TaskMQTT", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(taskRTC, "TaskRTC", 4096, NULL, 1, NULL, 1);
}

void loop() {}
