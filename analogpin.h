#pragma once
#include "color.h"


namespace control {


  color::RGB fetchAnalogPinColor() {
    color.RGB rgb;
    rgb.red = analogRead(analogControlRedPin) / 4;
    rgb.green = analogRead(analogControlGreenPin) / 4;
    rgb.blue = analogRead(analogControlBluePin) / 4;
    return rgb;
  }


} // namespace control
