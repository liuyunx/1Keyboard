#include "DigiKeyboard.h"
#include <Adafruit_NeoPixel.h>

const int ledPin = 1; 
const int keyPin = 2; 

Adafruit_NeoPixel led = Adafruit_NeoPixel(1, ledPin, NEO_GRB + NEO_KHZ800);
uint16_t fadeAmount = 10;
uint16_t brightness = 15;

void setup() {
  pinMode(keyPin, INPUT_PULLUP);
  led.begin(); 
  led.setPixelColor(0,led.Color(255,255,255));
  led.show();
}

void loop() {

      led.setBrightness(brightness);
      led.show();
      brightness = brightness + fadeAmount;
      DigiKeyboard.sendKeyStroke(0); // Fix for older systems
      if(digitalRead(keyPin)==LOW){
         DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT); 
      }
      DigiKeyboard.delay(120); 

      if(brightness <= 11 || brightness >= 240) {
         fadeAmount = -fadeAmount;
      }
}
