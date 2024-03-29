// Transbadge for c36c3
// Amanda, 15.09.2019

// Includes
#include <Adafruit_NeoPixel.h>

// Nodemcu data pin
#define LED_PIN    D5

// Number of pixels
#define LED_COUNT 32

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// setup() function -- runs once at startup --------------------------------
void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(10); // Set BRIGHTNESS to about 1/5 (max = 255)

    for (int i = 0; i < 5; i++)
  {
    startUp();
  }
}

// loop() function -- runs repeatedly as long as board is on ---------------
void loop() {

  transFlagShow();
  delay(5000);

  transFlagCease();
  delay(1000);


}

// Feather NeoPixel matrix adresses
//  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7
//  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15
// 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23
// 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31

// Arrays to define the rows, since flags are mostly row based
int row0[4] = {0, 8, 16, 24};
int row1[4] = {1, 9, 17, 25};
int row2[4] = {2, 10, 18, 26};
int row3[4] = {3, 11, 19, 27};
int row4[4] = {4, 12, 20, 28};
int row5[4] = {5, 13, 21, 29};
int row6[4] = {6, 14, 22, 30};
int row7[4] = {7, 15, 23, 31};

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

// script which runs at startup one time
void startUp() {
for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row0[i]), mayaBlue);
    strip.setPixelColor((row7[i]), mayaBlue);
  }
  strip.show();
  delay(200);
  strip.clear();

  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row1[i]), amaranthPink);
    strip.setPixelColor((row6[i]), amaranthPink);
  }
  strip.show();
  delay(200);
  strip.clear();

    for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row2[i]), amaranthPink);
    strip.setPixelColor((row5[i]), amaranthPink);
  }
  strip.show();
  delay(200);
  strip.clear();

for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row3[i]), white);
    strip.setPixelColor((row4[i]), white);
  }
  strip.show();
  delay(200);
  strip.clear();
}

void transFlagShow() {

  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row3[i]), white);
    strip.setPixelColor((row4[i]), white);
  }
  strip.show();
  delay(200);
  
    for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row2[i]), amaranthPink);
    strip.setPixelColor((row5[i]), amaranthPink);
  }
  strip.show();
  delay(200);

  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row1[i]), amaranthPink);
    strip.setPixelColor((row6[i]), amaranthPink);
  }
  strip.show();
  delay(200);

  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row0[i]), mayaBlue);
    strip.setPixelColor((row7[i]), mayaBlue);
  }
  strip.show();
  delay(200);
}

void transFlagCease() {

    for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row3[i]), off);
    strip.setPixelColor((row4[i]), off);
  }

  delay(200);
  
    for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row2[i]), off);
    strip.setPixelColor((row5[i]), off);
  }

  delay(200);

  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row1[i]), off);
    strip.setPixelColor((row6[i]), off);
  }

  delay(200);

  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row0[i]), off);
    strip.setPixelColor((row7[i]), off);
  }
}

  /*
  void transFlag() {
  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row0[i]), mayaBlue);
    strip.setPixelColor((row1[i]), amaranthPink);
    strip.setPixelColor((row2[i]), amaranthPink);
    strip.setPixelColor((row3[i]), white);
    strip.setPixelColor((row4[i]), white);
    strip.setPixelColor((row5[i]), amaranthPink);
    strip.setPixelColor((row6[i]), amaranthPink);
    strip.setPixelColor((row7[i]), mayaBlue);
  }  
 

void prideFlag() {
  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor((row0[i]), off);
    strip.setPixelColor((row1[i]), amaranthPink);
    strip.setPixelColor((row2[i]), blue);
    strip.setPixelColor((row3[i]), lightGreen);
    strip.setPixelColor((row4[i]), yellow);
    strip.setPixelColor((row5[i]), orange);
    strip.setPixelColor((row6[i]), red);
    strip.setPixelColor((row7[i]), off);
  }
}
*/