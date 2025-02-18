#pragma once
#include "color.h"


namespace control {


  color::RGB rainbow(float phaseDegrees) {
    color.HSV hsv;
    hsv.hue = phaseDegrees;
    hsv.saturation = 1;
    hsv.value = 1;
    return color.hsvToRgb(hsv);
  }


  color::RGB fetchRainbowColor() {
    float phase = millis() / 10.0;
    return rainbow(phase);
  }


} // namespace control
