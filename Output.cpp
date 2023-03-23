#include "Arduino.h"
#include <Wire.h>
#include <GOFi2cOLED.h>
#include <Output.h>

Output::Output(bool serialOn, bool oledOn) {
  _serialOn = serialOn;
  _oledOn = oledOn;
}

void Output::begin() {
  if (_serialOn) {
    Serial.begin(152000);
  }
  if (_oledOn) {
    _GOFoled.init(0x3C);  //initialze  OLED display
    _GOFoled.clearDisplay();
    _GOFoled.setTextSize(1);
    _GOFoled.setTextColor(WHITE);
    _GOFoled.setCursor(0,0);
  }
}

void Output::print(String msg) {
  if (_serialOn) {
    Serial.print(msg);
  }
  if (_oledOn) {
    _GOFoled.print(msg);
  }
}

void Output::println(String msg, bool display) {
  if (_serialOn) {
    Serial.println(msg);
  }
  if (_oledOn) {
    _GOFoled.println(msg);
    if (display) {
      _GOFoled.display();
    }
  }
}

void Output::clear() {
  _GOFoled.clearDisplay();
  _GOFoled.setCursor(0, 0);
}

void Output::display() {
  _GOFoled.display();
}
