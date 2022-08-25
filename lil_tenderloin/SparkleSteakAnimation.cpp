#include <Adafruit_NeoPixel.h>
#include "SparkleSteakAnimation.hh"
#include "LedConfig.hh"

SparkleSteakAnimation::SparkleSteakAnimation(
  Adafruit_NeoPixel _outter,
  Adafruit_NeoPixel _inner
): SteakAnimation (_outter, _inner) {}

void SparkleSteakAnimation::loopIteration() {
  setOutterRed();
  setInnerWhite();

  for (long i = 0; i < 2; i++) {
    outter.setPixelColor(random(0, LED_COUNT1), 0, 0, 0, 255);
  }
}

int SparkleSteakAnimation::getLoopDelayMS() {
  return 50;
}
