#pragma once
#include "color.h"

namespace control {


    color::RGB fetchEthernetColor() {
      color.RGB rgb;
      rgb.red = 0;
      rgb.green = 0;
      rgb.blue = 255;
      return rgb;
    }


} // namespace control
