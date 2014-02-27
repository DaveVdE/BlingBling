
// From strandtest:
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
Pixel Wheel(uint8_t WheelPos) {
  if(WheelPos < 85) {
   return Pixel(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return Pixel(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return Pixel(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

struct Rainbow
{
  Pixel operator()(int frame, int index)
  {
    int phase = (frame + (index * 16)) >> 8;
    return Wheel((uint8_t)phase);
  }  
};

