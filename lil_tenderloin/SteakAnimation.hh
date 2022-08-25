#include <Adafruit_NeoPixel.h>
#ifndef STEAKANIMATION_H
#define STEAKANIMATION_H


class SteakAnimation {
  public:
    void loop();

  protected:
    SteakAnimation(Adafruit_NeoPixel _outter, Adafruit_NeoPixel _inner);
    ~SteakAnimation();
    void setOutterRed();
    void setInnerWhite();
    Adafruit_NeoPixel outter;
    Adafruit_NeoPixel inner;
  private:
    void loopIteration();
    int getLoopDelayMS();
};

#endif
