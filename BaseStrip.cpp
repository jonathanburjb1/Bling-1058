// 
// 
// 
#include "BaseStrip.h"
#include <Adafruit_NeoPixel.h>
void baseStrip::set(int pos, int r, int g, int b, int strip) {
  pixels[strip].setPixelColor(pos, r, g, b);
}
void baseStrip::update(int strip) {
  pixels[strip].show();
}
int baseStrip::getNumPixels(int strip) {
  return(pixels[strip].numPixels());
}
baseStrip::baseStrip(){}
Adafruit_NeoPixel* baseStrip::pixels;
baseStrip::baseStrip(int* numPixels, int* pins) {
  numstrips = sizeof(numPixels) / sizeof(numPixels[0]);
  pixels = new Adafruit_NeoPixel[numstrips];
  for (int i = 0; i < numstrips; i++) {
    pixels[i] = Adafruit_NeoPixel(numPixels[i], pins[i], NEO_RGBW + NEO_KHZ800);
    pixels[i].begin();
  }
}


