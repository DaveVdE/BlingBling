
struct Flash
{
  uint8_t speed;
  
  Flash(uint8_t speed) : speed(speed) 
  {
  }
  
  Pixel operator()(int frame, int index)
  {
    if (frame % speed == 0) {
      return Pixel(255, 255, 255);
    } else {
      return Pixel(0, 0, 0);
    }
  }  

};
