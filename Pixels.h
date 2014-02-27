#include <Arduino>

struct Pixel {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  
  Pixel() : red(0), green(0), blue(0)
  {
  }
  
  Pixel(uint8_t red, uint8_t green, uint8_t blue)
    : red(red), green(green), blue(blue)
  {
  }
};

struct FixedPixel {
  Pixel pixel;
  
  FixedPixel(const Pixel& pixel) : pixel(pixel)
  {
  }
  
  Pixel operator()(int frame, int index)
  {
    return pixel;
  }  
};

uint8_t shiftValue(uint8_t value, int distance)
{
  return constrain(value + distance, 0, 255);
}

Pixel shiftPixel(Pixel pixel, int distance)
{
  return Pixel(
    shiftValue(pixel.red, distance),
    shiftValue(pixel.green, distance),
    shiftValue(pixel.blue, distance));
}

// Fades every pixel with the same offset.
template<class Pipeline>
struct Pulsating
{
  typedef Pipeline PipelineType;
  PipelineType& pipeline;
  
  Pulsating(PipelineType& pipeline) : pipeline(pipeline)
  {
  }
  
  Pixel operator()(int frame, int index)
  {
    int distance = (frame % 256);
    if (distance > 127) distance = 256 - distance;
    Pixel pixel = pipeline(frame, index);
    return shiftPixel(pixel, distance);
  }  
};

uint8_t fadeValue(uint8_t value, uint8_t level)
{
  return (uint16_t(value) * uint16_t(level)) >> 8;
}

Pixel fadePixel(Pixel pixel, uint8_t level)
{
  return Pixel(
    fadeValue(pixel.red, level),
    fadeValue(pixel.green, level),
    fadeValue(pixel.blue, level));
}

template<class Pipeline>
struct Swirl
{
  typedef Pipeline PipelineType;
  PipelineType& pipeline;

  Swirl(PipelineType& pipeline) : pipeline(pipeline)
  {    
  }

  Pixel operator()(int frame, int index)
  {
    int phase = (frame + (index * 64)) % 256;
    uint8_t level = phase > 127 ? (256 - phase) : phase;
    Pixel pixel = pipeline(frame, index);
    return fadePixel(pixel, level);
  }  
};

