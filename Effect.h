#include <Arduino>
#include <Adafruit_NeoPixel>
#include "Pixels.h"
#include "Rainbow.h"
#include "Slope.h"
#include "Sparkle.h"
#include "Flash.h"
#include "Nope.h"

struct IEffect {
  virtual void loop() = 0;
};

template<class Pipeline>
struct Effect : IEffect
{
  Pipeline& pipeline;
  Adafruit_NeoPixel& strip;
  int frame;
   
  Effect(Adafruit_NeoPixel& strip, Pipeline& pipeline) : strip(strip), pipeline(pipeline), frame(0)
  {
  }

  virtual void loop()
  {
    for (int index = 0; index < strip.numPixels(); ++index)
    {
      Pixel pixel = pipeline(frame, index);
      strip.setPixelColor(index, pixel.red, pixel.green, pixel.blue);
    }

    strip.show();
    ++frame;
  }
};
