#include <Adafruit_NeoPixel.h>
#include "App.h"

const uint8_t pin = 1;
const uint8_t pixelCount = 8;

Adafruit_NeoPixel strip(pixelCount, 1, NEO_GRB + NEO_KHZ800);

/*
typedef FixedPixel PixelType;
PixelType pixel(Pixel(0, 0, 0));
typedef Pulsating<PixelType> PulsatingType;
PulsatingType pulsating(pixel);
typedef App<PulsatingType> AppType;
AppType app(strip, pulsating);
*/

/*
typedef FixedPixel PixelType;
PixelType pixel(Pixel(127, 0, 0));
typedef Swirl<PixelType> SwirlType;
SwirlType swirl(pixel);
typedef App<SwirlType> AppType;
AppType app(strip, swirl);
*/

/*
*/

/*
typedef Rainbow RainbowType;
RainbowType rainbow;
typedef App<RainbowType> AppType;
AppType app(strip, rainbow);
*/

Pixel red(255, 0, 0);
Pixel green(0, 255, 0);
Pixel blue(0, 0, 255);
Pixel black(0, 0, 0);
Segment segment1(150, &red, &black);
Segment segment2(150, &green, &black);
Segment segment3(150, &blue, &black);
Segment end(255, &black, &black);
const Segment* segments[] = {&segment1, &segment2, &segment3, &end, 0};
Slope slope(segments);
typedef App<Slope> AppType;
AppType app(strip, slope);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
}

void loop() {  
  // put your main code here, to run repeatedly: 
  app.loop();
  delay(20);
}
