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
​
​
​
​
​
​
#include <Adafruit_NeoPixel.h>
#define LED_PIN1 6
#define LED_COUNT1 92
#define LED_PIN2 7
#define LED_COUNT2 21
​
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(LED_COUNT1, LED_PIN1, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(LED_COUNT2, LED_PIN2, NEO_RGBW + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.show(); // Initialize all pixels to 'off'
}
​
void loop() {
  // put your main code here, to run repeatedly:
  strip1.fill(strip1.Color(0,225,0), 0, LED_COUNT1);
  strip1.show();
  strip2.fill(strip2.Color(0,0,0,225), 0, LED_COUNT2);
  strip2.show();
  delay(25);
}
​
​
//void loop() {
//  // put your main code here, to run repeatedly:
//  #define ACTIVE_PIN 0;
//  //strip.fill(strip.Color(255, 0, 0, 0), 0, LED_COUNT);
//void loop() {
//  strip.setPixelColor(ACTIVE_PIN, 255, 0, 0, 0);
//  ACTIVE_PIN = ACTIVE_PIN + 1;
//}
//}
