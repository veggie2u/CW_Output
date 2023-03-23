
#ifndef OUTPUT_H
#define OUTPUT_H

#include "Arduino.h" 
#include <Wire.h>
#include <GOFi2cOLED.h>

class Output {
  public:
    Output(bool serialOn, bool oledOn);
    void begin();
    void print(String msg);
    void println(String msg, bool display=true);
    void clear();
    void display();
  private:
    bool _serialOn;
    bool _oledOn;
    GOFi2cOLED _GOFoled;
};
#endif