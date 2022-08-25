#include <Adafruit_NeoPixel.h>
#include "SteakAnimation.h"
#include "SparkleSteakAnimation.h"
#include "LedConfig.h"

Adafruit_NeoPixel outter = Adafruit_NeoPixel(LED_COUNT1, LED_PIN1, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel inner = Adafruit_NeoPixel(LED_COUNT2, LED_PIN2, NEO_RGBW + NEO_KHZ800);

void initializeStrip(Adafruit_NeoPixel strip) {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

SteakAnimation animations[] = {
  SparkleSteakAnimation(outter, inner)
};

long animationSelector = random(0, sizeof(animations));

// put your setup code here, to run once:
void setup() {
  inner.begin();
  inner.show(); // Initialize all pixels to 'off'
  outter.begin();
  outter.show(); // Initialize all pixels to 'off'
}

void loop() {
  animations[animationSelector].loop();
}


// back and forth between red and white
// neon green or something unexpected
// fade to a color like orange
