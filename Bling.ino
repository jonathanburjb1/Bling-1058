#include <Wire.h>
//#include <Keyboard.h>
/*
 Name:    Sketch1.ino
 Created: 1/30/2017 3:04:46 PM
 Author:  Jonathan
*/
#include <Adafruit_NeoPixel.h>
#include "QuantitativeIndicator.h"
#include "BaseStrip.h"
#include "HSV2RGB.h"
bool rainbows = false;
int numpixels[1] = { 77 };
int pins[1] = { 6 };
byte var = 0;
baseStrip stripstrip = baseStrip(numpixels, pins);
quantitativeIndicator QI = quantitativeIndicator(numpixels[0], 0, 0);
void setup() {
  Wire.begin(84);
  int num;
  QI.update(255);
  Wire.onReceive(i2cHandler);
  Serial.begin(9600);
  //Keyboard.begin();
  QI.solid(0, 255, 0);
}
void rainbow(){
  HSV2RGB roy;
  for(int h =0; h<numpixels[0];h++){
    roy.hs.h = h*360/numpixels[0];
    roy.hs.s = 1;
    roy.hs.v = 1;
    roy.rg = roy.hsv2rgb(roy.hs);
    QI.scrollset(h, roy.rg.r*255, roy.rg.g*255, roy.rg.b*255);
  }
  QI.scroll(10, numpixels[0]);
}
void ALcheck(int tof){
  for(int i = 0; i<numpixels[0]; i++){
    if(i%8<4){
      QI.scrollset(i, 255, 255, 255);
    }else{
      if(tof==1){
        QI.scrollset(i, 0, 255, 0);
      }else if (!tof){
        QI.scrollset(i, 0, 0, 255);
      }else if (tof==2){
         QI.scrollset(i, 255, 0, 0);
      }
    }
  }
  QI.scroll(50, numpixels[0]);
}
void defaulet(){
  for(int i =0; i<numpixels[0]; i++){
    if(!(i%(numpixels[0]/4))){
      QI.scrollset(i, 0, 255, 0);
     }
     else{
      QI.scrollset(i, 100, 100, 100);
     }
  }
  QI.scroll(100, numpixels[0]);
}
void i2cHandler(int notused){
  if(Wire.available()){
    var = Wire.read();
    Serial.println(var);
    if(!rainbows){
      switch(var){//Wire.read()){//*
         case(0):
            QI.solid(0, 255, 0);
            QI.flash(800, 0, 0, 0, true);
            //defaulet();
            break;
          case(1):
            QI.flash(0, 0, 0, 0, false);
            QI.solid(0, 255, 0);
            break;
          case(2):
            QI.flash(0, 0, 0, 0, false);
            QI.solid(0, 0, 255);
            break;
          case(3):
            QI.flash(0, 0, 0, 0, false);
            ALcheck(1);       
            break;
          case(4):
            QI.flash(0, 0, 0, 0, false);
            ALcheck(0);
            break;
          case(5):
            QI.flash(0, 0, 0, 0, false);
            QI.solid(255, 255, 0);
            break;
          case(6):
            QI.flash(0, 0, 0, 0, false);
            QI.solid(255, 0, 0);
            break;
          case(7):
            QI.flash(0, 0, 0, 0, false);
            rainbow();
            rainbows = true;
            break;
          case (8):
            QI.flash(0, 0, 0, 0, false);
            ALcheck(2);
            break;
          case (9):
            QI.solid(255, 0, 0);
            QI.flash(500, 0, 0, 0, true);
            break;
          default:
            defaulet();
            break;
      }//*
    }//*
  }
}
void loop() {
  //Serial.println(millis());
  delay(1);
  //if(Wire.available()>0) i2cHandler(0);
  QI.incTime();
}

