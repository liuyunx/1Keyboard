#include "DigiKeyboard.h"
#include <Adafruit_NeoPixel.h>

const int ledPin = 1; 
const int keyPin = 2; 

int backlightBrightness = 150; 

Adafruit_NeoPixel led = Adafruit_NeoPixel(1, ledPin, NEO_GRB + NEO_KHZ800);
uint16_t j;

void setup() {
  pinMode(keyPin, INPUT_PULLUP);
  led.begin(); 
  led.setBrightness(backlightBrightness);
  led.show();
}

void loop() {
  for(j=0; j<256; j++) {
      led.setPixelColor(0, Wheel(j & 255));
      led.show();
      DigiKeyboard.sendKeyStroke(0); // Fix for older systems
      if(digitalRead(keyPin)==LOW){
         DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
      }
      DigiKeyboard.delay(120); 
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return led.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return led.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return led.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}
