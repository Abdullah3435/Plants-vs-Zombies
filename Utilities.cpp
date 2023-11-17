#include "Utilities.hpp"

bool Utilities::Delay(int delay)
{
    static int framedelay = 0;
    framedelay ++;
    if (framedelay > delay)
    {
      framedelay=0;
      return true;
    }
    return false;
  }