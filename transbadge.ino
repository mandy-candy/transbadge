// Transbadge for c36c3
// Amanda

// Includes
#include <Adafruit_NeoPixel.h>

// Nodemcu data pin
#define LED_PIN    D5

// Number of pixels
#define LED_COUNT 32

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
/*
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
*/

// setup() function -- runs once at startup --------------------------------
void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(10); // Set BRIGHTNESS to about 1/5 (max = 255)
}

// loop() function -- runs repeatedly as long as board is on ---------------
void loop() {

  transFlag();
  strip.show();
  delay(5000);

  prideFlag();
  strip.show();
  delay(5000);
}

// Feather NeoPixel matrix adresses
//  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7
//  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15
// 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23
// 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31

// Arrays to define the rows, since flags are mostly row based
int row1[4] = {0, 8, 16, 24};
int row2[4] = {1, 9, 17, 25};
int row3[4] = {2, 10, 18, 26};
int row4[4] = {3, 11, 19, 27};
int row5[4] = {4, 12, 20, 28};
int row6[4] = {5, 13, 21, 29};
int row7[4] = {6, 14, 22, 30};
int row8[4] = {7, 15, 23, 31};

// Color declaration
// Transflag
uint32_t mayaBlue = strip.Color(0, 128, 255);
uint32_t amaranthPink = strip.Color(255, 0, 127);
uint32_t white = strip.Color(255, 255, 255);
// prideFlag
uint32_t darkViolet = strip.Color(75, 0, 130);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t lightGreen = strip.Color(0, 255, 0);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t orange = strip.Color(255, 128, 0);
uint32_t red = strip.Color(204, 0, 0);
uint32_t off = strip.Color(0, 0, 0);

void transFlag() {
  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row1[i]), mayaBlue);
    strip.setPixelColor((row2[i]), amaranthPink);
    strip.setPixelColor((row3[i]), amaranthPink);
    strip.setPixelColor((row4[i]), white);
    strip.setPixelColor((row5[i]), white);
    strip.setPixelColor((row6[i]), amaranthPink);
    strip.setPixelColor((row7[i]), amaranthPink);
    strip.setPixelColor((row8[i]), mayaBlue);
  }  
}

void prideFlag() {
  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row1[i]), off);
    strip.setPixelColor((row2[i]), amaranthPink);
    strip.setPixelColor((row3[i]), blue);
    strip.setPixelColor((row4[i]), lightGreen);
    strip.setPixelColor((row5[i]), yellow);
    strip.setPixelColor((row6[i]), orange);
    strip.setPixelColor((row7[i]), red);
    strip.setPixelColor((row8[i]), off);
  }
}