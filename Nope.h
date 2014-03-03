struct Nope
{
  Pixel operator()(int frame, int index)
  {    
    return Pixel(0, 0, 0);
  }  
};
