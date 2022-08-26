//
//#include <Adafruit_NeoPixel.h>
//
//#define PIN      6
//#define N_LEDS 47
//
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_RGBW + NEO_KHZ800);
//
//void setup() {
//  strip.begin();
//}
//
//void loop() {
//  chase(strip.Color(255, 0, 0)); // Red
//  chase(strip.Color(0, 255, 0)); // Green
//  chase(strip.Color(0, 0, 255)); // Blue
//}
//
//static void chase(uint32_t c) {
//  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
//      strip.setPixelColor(i  , c); // Draw new pixel
//      //strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
//      strip.show();
//      delay(25);
//  }
//}


#include <Adafruit_NeoPixel.h>

#define OUTER_PIN 6
#define OUTER_COUNT 92

#define INNER_PIN 7
#define INNER_COUNT 20

Adafruit_NeoPixel outer = Adafruit_NeoPixel(OUTER_COUNT, OUTER_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel inner = Adafruit_NeoPixel(INNER_COUNT, INNER_PIN, NEO_RGBW + NEO_KHZ800);


int animationSelector = 0;

void setup() {
  outer.begin();
  outer.show();
  inner.begin();
  inner.show();
  fillOuterRed();
  fillInnerWhite();
  animationSelector = random(0, 6);
}


void loop() {
  switch (animationSelector) {
    case 0:
      steadyAnimation();
      break;
    case 1:
      sparkleAnimation();
      break;
    case 2:
      chaseTwo();
      break;
    case 3:
      colorSwitch();
      break;
    case 4:
      fullRandom();
      break;
    case 5:
      cottonCandy();
      break;
  }
}

void fillOuterRed() {
  outer.fill(outer.Color(0,255,0), 0, OUTER_COUNT);
}

void fillInnerWhite() {
  inner.fill(inner.Color(0,0,0,255), 0, INNER_COUNT);
}


void steadyAnimation() {
  fillOuterRed();
  fillInnerWhite();

  outer.show();
  inner.show();

  delay(50);
}

void sparkleAnimation() {
  fillOuterRed();
  fillInnerWhite();

  for (long i = 0; i < 3; i++) {
    outer.setPixelColor(random(0, OUTER_COUNT), 0, 0, 0, 255);
  }

  outer.show();
  inner.show();

  delay(50);
}


int chaseSubtractIndex(int start, int subtract, int ledCount) {
  if (start < subtract) {
    return (start + ledCount) - subtract;
  } else {
    return start - subtract;
  }
}

int chaseAddIndex(int start, int addition, int ledCount) {
  int result = start + addition;

  if (result >= ledCount) {
    return result - ledCount;
  } else {
    return result;
  }
}


const int TAIL_LENGTH = 10;
const int INNER_TAIL_LENGTH = 3;
int currentChaseIndex = 0;
int currentInnerChaseIndex = 0;

void chase() {
  fillOuterRed();
  fillInnerWhite();

  for (int tailCounter = 0; tailCounter < TAIL_LENGTH; tailCounter++) {
    int ledIndex = chaseSubtractIndex(currentChaseIndex, tailCounter, OUTER_COUNT);
    int intensity = (255 * (TAIL_LENGTH - tailCounter)) / TAIL_LENGTH;
    outer.setPixelColor(ledIndex, 0, 255 - intensity, 0, intensity );
  }
  for (int tailCounter = 0; tailCounter < INNER_TAIL_LENGTH; tailCounter++) {
    inner.setPixelColor(chaseSubtractIndex(currentInnerChaseIndex, tailCounter, INNER_COUNT), 0, 255, 0, 0);
  }

  currentChaseIndex = chaseAddIndex(currentChaseIndex, 1, OUTER_COUNT);
  currentInnerChaseIndex = chaseAddIndex(currentInnerChaseIndex, 1, INNER_COUNT);

  outer.show();
  inner.show();
  delay(50);
}

int chase0currentIndex = 0;
int chase1currentIndex = OUTER_COUNT / 2;

void chaseTwo() {
  fillOuterRed();
  fillInnerWhite();

  for (int tailCounter = 0; tailCounter < TAIL_LENGTH; tailCounter++) {
    int intensity = (255 * (TAIL_LENGTH - tailCounter)) / TAIL_LENGTH;
    outer.setPixelColor(chaseSubtractIndex(chase0currentIndex, tailCounter, OUTER_COUNT), 0, 255 - intensity, 0, intensity);
    outer.setPixelColor(chaseSubtractIndex(chase1currentIndex, tailCounter, OUTER_COUNT), 0, 255 - intensity, 0, intensity);
  }
  chase0currentIndex = chaseAddIndex(chase0currentIndex, 1, OUTER_COUNT);
  chase1currentIndex = chaseAddIndex(chase1currentIndex, 1, OUTER_COUNT);

  outer.show();
  inner.show();
  delay(50);
}

int chaseSimpleOutterIndex = 0;
int chaseSimpleInnerIndex = 0;
const int CHASE_SIMPLE_LENGTH = 5;

void chaseSimple() {
  fillOuterRed();
  fillInnerWhite();

  for (int i = 0; i < CHASE_SIMPLE_LENGTH; i++) {
    int outerIndex = chaseAddIndex(chaseSimpleOutterIndex, i, OUTER_COUNT);
    int innerIndex = chaseAddIndex(chaseSimpleInnerIndex, i, INNER_COUNT);

    outer.setPixelColor(outerIndex, 0, 0, 0, 0);
    inner.setPixelColor(innerIndex, 0, 0, 0, 0);
  }

  chaseSimpleOutterIndex = chaseAddIndex(chaseSimpleOutterIndex, 1, OUTER_COUNT);
  chaseSimpleInnerIndex = chaseAddIndex(chaseSimpleInnerIndex, 1, INNER_COUNT);

  outer.show();
  inner.show();
  delay(50);
}

int slowSparkle0Index = 0;
int slowSparkle0Width = 0;

int slowSparkle0LoopCount = 0;
int slowSparkle0Duration = 0;

int slowSparkle0CycleDuration = 0;

void slowSparkle() {
  if (slowSparkle0LoopCount == slowSparkle0Duration) {
    fillOuterRed();

    slowSparkle0Index = random(0, OUTER_COUNT);
    slowSparkle0Width = random(4, 9);

    slowSparkle0LoopCount = 1;
    slowSparkle0Duration = random(5, 30);

    slowSparkle0CycleDuration = random(40, 60);
  }

  if (slowSparkle0CycleDuration - slowSparkle0Duration < slowSparkle0LoopCount) {
    int sparkleLoopCount = slowSparkle0LoopCount - (slowSparkle0CycleDuration - slowSparkle0Duration);
    int slowSparkleDistanceFromZero =
      sparkleLoopCount < slowSparkle0Duration / 2
        ? sparkleLoopCount
        : slowSparkle0Duration - sparkleLoopCount;

    int intensity0 = (255 * slowSparkleDistanceFromZero) / (slowSparkle0Duration / 2);

    for(int i = 0; i < slowSparkle0Width; i++) {
      int pixelDistanceFromZero =
        i < slowSparkle0Width / 2
          ? i
          : slowSparkle0Width - i;

      int intensity1 = (255 * pixelDistanceFromZero) / (slowSparkle0Width / 2);

      int totalIntensity = (intensity0 * intensity1) / 255;

      outer.setPixelColor(chaseAddIndex(slowSparkle0Index, i, OUTER_COUNT), 0, 255-totalIntensity, 0, totalIntensity);
    }
  }

  slowSparkle0LoopCount++;

  outer.show();
  inner.show();
  delay(50);
}

int colorSwitchCycleLoopCount = 0;
int colorSwitchCycleDuration = 0;

const int COLOR_TOGGLE_DURATION = 5;
const int COLOR_TOGGLE_HALF_DURATION = COLOR_TOGGLE_DURATION / 2;

void colorSwitch() {
  if (colorSwitchCycleLoopCount == colorSwitchCycleDuration) {
    colorSwitchCycleDuration = random(120, 480);
    colorSwitchCycleLoopCount = 1;
  }

  if (colorSwitchCycleDuration - COLOR_TOGGLE_DURATION < colorSwitchCycleLoopCount) {
    int toggleLoopCount = colorSwitchCycleLoopCount - (colorSwitchCycleDuration - COLOR_TOGGLE_DURATION);
    int colorSwitchCycleDistanceFromZero =
      toggleLoopCount < COLOR_TOGGLE_HALF_DURATION
        ? toggleLoopCount
        : COLOR_TOGGLE_DURATION - toggleLoopCount;

    int intensity = (255 * colorSwitchCycleDistanceFromZero) / COLOR_TOGGLE_HALF_DURATION;
    outer.fill(outer.Color(0, 255 - intensity, 0, intensity), 0, OUTER_COUNT);
    inner.fill(inner.Color(0, intensity, 0, 255 - intensity), 0, INNER_COUNT);
  } else {
    fillOuterRed();
    fillInnerWhite();
  }
  colorSwitchCycleLoopCount++;

  outer.show();
  inner.show();
  delay(50);
}

void fullRandom() {

  outer.fill(outer.Color(random(0, 256), random(0, 256), random(0, 256), 0), 0, OUTER_COUNT);
  inner.fill(inner.Color(random(0, 256), random(0, 256), random(0, 256), 0), 0, INNER_COUNT);

  outer.show();
  inner.show();
  delay(random(50, 200));
}

void cottonCandy() {

  for (int i = 0; i < INNER_COUNT; i++) {
    inner.setPixelColor(i, random(0, 256), random(0, 256), random(0, 256), 0);
  }

  for (int i = 0; i < OUTER_COUNT; i++) {
    outer.setPixelColor(i, random(0, 256), random(0, 256), random(0, 256), 0);
  }

  outer.show();
  inner.show();
  delay(random(50, 200));
}
