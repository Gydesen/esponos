
// Debug Stuf
//
//
#define DEBUG_SERIAL TRUE
#define DEBUG_SCREEN TRUE


// MQTT
//
//
#define MQTT_SERVER         "192.168.1.31"
#define MQTT_PORT           1883
#define MQTT_TOPIC          "sonos/"

// Display Stuf
//
//
#define USE_DISPLAY         TRUE
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);


// WIFI Stuff
//
//