#include <Adafruit_NeoPixel.h>
#include "Effect.h"

const uint8_t pin = 1;
const uint8_t pixelCount = 16;

Adafruit_NeoPixel strip(pixelCount, 1, NEO_GRB + NEO_KHZ800);

Pixel red(255, 0, 0);
Pixel green(0, 255, 0);
Pixel blue(0, 0, 255);
Pixel black(0, 0, 0);
Pixel fire1(95, 50, 0);
Pixel fire2(32, 10, 0);

Segment redBlack(64, &red, &black);
Segment greenBlack(64, &green, &black);
Segment blueBlack(64, &blue, &black);
Segment empty(64, &black, &black);

Rainbow rainbow;
Effect<Rainbow> rainbowEffect(strip, rainbow);

const Segment* policeSegments[] = {&redBlack, &empty, &blueBlack, &empty, 0};
Slope police(policeSegments, 8);
Effect<Slope> policeEffect(strip, police);

Segment fireA(64, &black, &fire1);
Segment fireB(64, &fire1, &fire2);
const Segment* fireSegments[] = {&fireA, &fireB, 0};
Slope fireSlope(fireSegments, 8);
typedef Pulsating<Slope> PulsingSlope;
PulsingSlope firePulse(fireSlope);
Effect<PulsingSlope> fireSlopeEffect(strip, firePulse);

Segment ringA(64, &black, &blue);
Segment ringB(64, &blue, &black);
const Segment* ringSegments[] = {&ringA, &ringB, &empty, &empty, 0};
Slope blueRing(ringSegments, 1);
Effect<Slope> ringEffect(strip, blueRing);

Sparkle sparkle(64);
Effect<Sparkle> sparkleEffect(strip, sparkle);

Flash flash(64);
Effect<Flash> flashEffect(strip, flash);

Nope nope;
Effect<Nope> nopeEffect(strip, nope);

const int buttonPin = 2;
const int ledPin =  13;      // the number of the LED pin

void setup() {
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH); // Internal pull-up, button connects to ground.

  strip.begin();
  strip.show();  
}

IEffect* effects[] = {&nopeEffect, &rainbowEffect, &policeEffect, &fireSlopeEffect, &ringEffect, &sparkleEffect, &flashEffect, 0};
IEffect** effectPtr = effects;

void loop() {  
  IEffect* effect = *effectPtr;
  effect->loop();
  
  int button = digitalRead(buttonPin);
  
  if (button == LOW) {
    ++effectPtr;
    if (*effectPtr == 0) effectPtr = effects;

    for (uint16_t index = 0; index < strip.numPixels(); ++index) strip.setPixelColor(index, 0);    
    strip.show();
    delay(1000);
  }
  
  digitalWrite(ledPin, LOW);
  delay(20);
}
