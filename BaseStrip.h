// BaseStrip.h
#include "Adafruit_NeoPixel.h"
#ifndef _BASESTRIP_h
#define _BASESTRIP_h
class baseStrip {
public:
  baseStrip();
  baseStrip(int* numPixels, int* pins);
  void set(int pos, int r, int g, int b, int strip);
  void update(int strip);
  int getNumPixels(int strip);
private:
  static Adafruit_NeoPixel* pixels;
  int numstrips;
};

#endif


