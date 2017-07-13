// 
// 
// 
#include "QuantitativeIndicator.h"
#include "BaseStrip.h"
using namespace std;
void quantitativeIndicator::setStrip(int strips) {
  strip = strips;
}
quantitativeIndicator::quantitativeIndicator(int spaces, int positions, int strips) { 
  space = spaces;
  pos = positions;
  strip = strips;
}
void quantitativeIndicator::flash(double speede, int r, int g, int b, bool on) {
  flashs = on;
  flashStruct.timee = speede;
  flashStruct.r = r;
  flashStruct.g = g;
  flashStruct.b = b;
  flashStruct.of = true;
}
void quantitativeIndicator::scrollset(int relposition, int r, int g, int b) {
  scrollStruct.r[relposition] = r;
  scrollStruct.g[relposition] = g;
  scrollStruct.b[relposition] = b;
}
void quantitativeIndicator::scroll(int timse, int nums) {
  scrollStruct.relposition = 0;
  scrollStruct.timee = timse;
  scrollStruct.num = nums;
  scrolls = true;
  solids = false;
}
void quantitativeIndicator::solid(int r, int g, int b) {
  solids = true;
  scrolls= false;
  solidStruct.r = r;
  solidStruct.g = g;
  solidStruct.b = b;
}
void quantitativeIndicator::update(byte val) {
  value = map(val, 0, 255, 0, space);
}
void quantitativeIndicator::setTime(int times) {
  timee = times;
}
void quantitativeIndicator::othercolor(int r, int g, int b) {
  OCStruct.r = r;
  OCStruct.g = g;
  OCStruct.b = b;
}
void quantitativeIndicator::drawOtherColor() {
  for (int i = value; i < space; i++) {
    base.set(i, OCStruct.r, OCStruct.g, OCStruct.b, strip);
  }
  base.update(strip);
}
void quantitativeIndicator::incTime() {
  timee++;
  switch (solids+flashs*2+scrolls*4)
  {
  case 1:
    if (timee % 100 == 0) {
      for (int i = pos; i < value; i++) {
        base.set(i, solidStruct.r, solidStruct.g, solidStruct.b, strip);
      }
      drawOtherColor();
    }
    break;
  case 3:
    if (timee % 10 == 0 && flashStruct.of) {
      for (int i = pos; i < value; i++) {
        base.set(i, solidStruct.r, solidStruct.g, solidStruct.b, strip);
      }
      drawOtherColor();
    }
    else if (timee % 10 == 0 && !flashStruct.of) {
      for (int i = pos; i < value; i++) {
        base.set(i, flashStruct.r, flashStruct.g, flashStruct.b, strip);
      }
      drawOtherColor();
    }
    if (timee%flashStruct.timee==0) {
      flashStruct.of = !flashStruct.of;
    }
    break;
  case 4:
    if (timee%scrollStruct.timee == 0) {
      scrollStruct.relposition++;
    }
    if (timee % 10 == 0) {
      for (int i = pos; i < value; i+=scrollStruct.num) {
        for (int j = 0; j < scrollStruct.num; j++) {
          if (i + (j+scrollStruct.relposition)%scrollStruct.num <= value) {
            base.set(i + (j+scrollStruct.relposition)%scrollStruct.num, scrollStruct.r[j], scrollStruct.g[j], scrollStruct.b[j], strip);
          }
        }
      }
      drawOtherColor();
    }
    break;
  case 6:
    if (timee % 10 == 0 && flashStruct.of) {
      if (timee%scrollStruct.timee == 0) {
        scrollStruct.relposition++;
      }
      if (timee % 10 == 0) {
        for (int i = pos; i < value; i += scrollStruct.num) {
          for (int j = 0; j < scrollStruct.num; j++) {
            if (i + (j + scrollStruct.relposition) % scrollStruct.num <= value) {
              base.set(i + (j + scrollStruct.relposition) % scrollStruct.num, scrollStruct.r[j], scrollStruct.g[j], scrollStruct.b[j], strip);
            }
          }
        }
      }
      drawOtherColor();
    }
    else if (timee % 10 == 0 && !flashStruct.of) {
      for (int i = pos; i < space; i++) {
        base.set(i, flashStruct.r, flashStruct.g, flashStruct.b, strip);
      }
      drawOtherColor();
    }
    if (timee%flashStruct.timee == 0) {
      flashStruct.of = !flashStruct.of;
    }
    break;
  default:
    break;
  }
}
