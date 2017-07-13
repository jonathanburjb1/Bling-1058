#ifndef HSV2RGB_h
#define HSV2RGB_h
class HSV2RGB{
  public:
    struct rgb {
      double r;       // a fraction between 0 and 1
      double g;       // a fraction between 0 and 1
      double b;       // a fraction between 0 and 1
  };
  rgb rg;
    struct hsv{
      double h;       // angle in degrees
      double s;       // a fraction between 0 and 1
      double v;       // a fraction between 0 and 1
  };
  hsv hs;
  
  static hsv   rgb2hsv(rgb in);
  static rgb   hsv2rgb(hsv in);
};
#endif
