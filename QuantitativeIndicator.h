// QuantitativeIndicator.h
#include "BaseStrip.h"
#ifndef _QUANTITATIVEINDICATOR_h
#define _QUANTITATIVEINDICATOR_h

//make sure delay is set to 1 ms before invoking any functions involving timing!
class quantitativeIndicator {
public:
  void flash(double speede, int r, int g, int b, bool on);
  void scroll(int timse, int num);
  void scrollset(int relposition, int r, int g, int b);
  void solid(int r, int g, int b);
  void othercolor(int r, int g, int b);
  void setTime(int times);
  quantitativeIndicator(int spaces, int positions, int strips);
  void update(byte val);
  void incTime();
  void setStrip(int strips);
private:
  void drawOtherColor();
  int pos;
  int space;
  baseStrip base;
  long long timee;
  int strip;
  int value;
  bool flashs;
  bool scrolls;
  bool solids; 
  struct soliddatastruct {
    int r;
    int g, b;
  }solidStruct;
  struct scrolldatastruct {
    int num;
    int relposition;
    int timee;
    int r[255];
    int g[255];
    int b[255];
  }scrollStruct;
  struct othercolordatastruct {
    int r, g, b;
  }OCStruct;
  struct flashdatastruct {
    int timee, r, g, b;
    bool of = false;
  }flashStruct;
};

#endif


