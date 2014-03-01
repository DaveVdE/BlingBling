
struct Sparkle
{
  uint8_t maximum;
  uint8_t lucky;
  
  Sparkle(uint8_t maximum) : maximum(maximum) 
  {
  }
  
  Pixel operator()(int frame, int index)
  {
    if (index == 0) 
    {
      lucky = random(maximum);
    }    
    
    if (index == lucky) {
      return Pixel(255, 255, 255);
    } else {
      return Pixel(0, 0, 0);
    }
  }  

};
