#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         
#include <WiFiClient.h>
#include <PubSubClient.h>

#include "my_user_config.h"
#include "helpers/hlpr_mqtt.h"
#include "helpers/hlpr_display.h"



WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;


void setup() {
  Serial.begin(115200);
  
  WiFiManager wifiManager;
  wifiManager.autoConnect("AutoConnectAP");

  //MQTT stuf
  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);

  // Display Stuff
  #ifdef USE_DISPLAY
    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); // Address 0x3C for 128x32
    Serial.println("we have defined USE_DISPLAY");
  #endif
  
}
void loop() {
  hlpr_display();

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outTopic", msg);
  }
}

