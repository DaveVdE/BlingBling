
struct Segment
{
  uint8_t length;
  const Pixel* left;
  const Pixel* right;
  
  Segment()
  {}
  
  Segment(uint8_t length, const Pixel* left, const Pixel* right) : length(length), left(left), right(right)
  {
  }
};

struct Slope
{
  const Segment** first;
  
  Slope(const Segment** first) : first(first)
  {
  }
  
  Pixel operator()(int frame, int index)
  {
    int phase = (frame + (index * 16)) & 0xff;
    const Segment** ptr = first;
    const Segment* segment = *ptr;
    
    while (ptr != 0 && phase > segment->length) {
      phase -= segment->length;
      ++ptr;
      if (ptr == 0) ptr = first;
      segment = *ptr;
    }
    
    uint8_t red = map(phase, 0, 255, segment->left->red, segment->right->red);
    uint8_t green = map(phase, 0, 255, segment->left->green, segment->right->green);
    uint8_t blue = map(phase, 0, 255, segment->left->blue, segment->right->blue);

    return Pixel(red, green, blue);
  }  
};
