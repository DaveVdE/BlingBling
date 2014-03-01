#include <Adafruit_NeoPixel.h>
#include "App.h"

const uint8_t pin = 1;
const uint8_t pixelCount = 16;

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
typedef Rainbow RainbowType;
RainbowType rainbow;
typedef App<RainbowType> AppType;
AppType app(strip, rainbow);
*/


/*
Pixel red(255, 0, 0);
Pixel green(0, 255, 0);
Pixel blue(0, 0, 255);
Pixel black(0, 0, 0);
Segment segment1(64, &red, &black);
Segment segment2(64, &green, &black);
Segment segment3(64, &blue, &black);
Segment empty(64, &black, &black);
const Segment* segments[] = {&segment1, &empty, &segment3, &empty, 0};
Slope slope(segments, 8);
typedef Pulsating<Slope> PulsingSlope;
PulsingSlope pulse(slope);
typedef App<PulsingSlope> AppType;
AppType app(strip, pulse);
*/

/*
Pixel red(255, 0, 0);
Pixel green(0, 255, 0);
Pixel blue(0, 0, 255);
Pixel black(0, 0, 0);
Pixel fire1(95, 50, 0);
Pixel fire2(32, 10, 0);
Segment segment1(64, &red, &black);
Segment segment2(64, &green, &black);
Segment segment3(64, &blue, &black);
Segment segment4(64, &black, &fire1);
Segment segment5(64, &fire1, &fire2);
Segment empty(64, &black, &black);
const Segment* segments[] = {&segment4, &segment5, 0};
Slope slope(segments, 8);
typedef Pulsating<Slope> PulsingSlope;
PulsingSlope pulse(slope);
typedef App<PulsingSlope> AppType;
AppType app(strip, pulse);
*/

Sparkle sparkle(64);
typedef App<Sparkle> AppType;
AppType app(strip, sparkle);

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
