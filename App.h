#include <Arduino>
#include <Adafruit_NeoPixel>
#include "Pixels.h"
#include "Rainbow.h"
#include "Slope.h"
#include "Sparkle.h"

template<class Pipeline>
struct App
{
  Pipeline& pipeline;
  Adafruit_NeoPixel& strip;
  int frame;
   
  App(Adafruit_NeoPixel& strip, Pipeline& pipeline) : strip(strip), pipeline(pipeline), frame(0)
  {
  }

  void loop()
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
