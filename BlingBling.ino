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

typedef Rainbow RainbowType;
RainbowType rainbow;
typedef App<RainbowType> AppType;
AppType app(strip, rainbow);



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
