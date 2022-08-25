#ifndef SPARKLESTEAKANIMATION_H
#define SPARKLESTEAKANIMATION_H
#include "SteakAnimation.hh"

class SparkleSteakAnimation: public SteakAnimation {
  public:
    SparkleSteakAnimation(
      Adafruit_NeoPixel _outter,
      Adafruit_NeoPixel _inner
    );
    ~SparkleSteakAnimation();
  protected:
    void loopIteration();
    int getLoopDelayMS();
};

#endif
