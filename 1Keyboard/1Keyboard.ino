#include "DigiKeyboard.h"

#include <Adafruit_NeoPixel.h>

const int ledPin = 1; // RGB LED 引脚
const int keyPin = 2; // 按键引脚

int backlightR = 0; // 红色值（0-255）
int backlightG = 255; // 绿色值（0-255）
int backlightB = 255; // 蓝色值（0-255）
int backlightBrightness = 100; // 亮度值（0-255）

Adafruit_NeoPixel led = Adafruit_NeoPixel(1, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(keyPin, INPUT_PULLUP);
  led.begin(); 
  led.show();
  led.setBrightness(backlightBrightness);
  led.setPixelColor(0, backlightR, backlightG, backlightB);
  led.show();
}

void loop() {
  DigiKeyboard.sendKeyStroke(0); 
  if(digitalRead(keyPin)==LOW){
    DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT); //这个是按键功能，这里是 WIN+D，更多键值，直接在 DigiKeyboard.h 中寻找
  }
  DigiKeyboard.delay(100); // 防抖延时
}
