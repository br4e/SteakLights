#include <Adafruit_NeoPixel.h>
#include "SteakAnimation.hh"
#include "LedConfig.hh"

SteakAnimation::SteakAnimation(
  Adafruit_NeoPixel _outter,
  Adafruit_NeoPixel _inner
) {
  outter = _outter;
  inner = _inner;
}

SteakAnimation::~SteakAnimation() {}

void SteakAnimation::loopIteration() {
  Serial.write("SteakAnimation::loopIteration()");
}

int SteakAnimation::getLoopDelayMS() {
  return 50;
}


void SteakAnimation::loop() {
  loopIteration();

  outter.show();
  inner.show();

  delay(getLoopDelayMS());
}

void SteakAnimation::setOutterRed() {
  outter.fill(outter.Color(0,255,0), 0, LED_COUNT1);
}

void SteakAnimation::setInnerWhite() {
  inner.fill(inner.Color(0,0,0,255), 0, LED_COUNT2);
}
