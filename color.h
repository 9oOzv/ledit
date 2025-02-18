#pragma once

namespace color {

  struct RGB {
    byte red;
    byte green;
    byte blue;
  };

  struct HSV {
    float hue;
    float saturation;
    float value;
  };

  RGB hsvToRgb(HSV hsv) {
    RGB rgb;
    float c = hsv.value * hsv.saturation;
    float x = c * (1 - abs(fmod(hsv.hue / 60, 2) - 1));
    float m = hsv.value - c;
    float r, g, b;
    if (hsv.hue < 60) {
      r = c;
      g = x;
      b = 0;
    } else if (hsv.hue < 120) {
      r = x;
      g = c;
      b = 0;
    } else if (hsv.hue < 180) {
      r = 0;
      g = c;
      b = x;
    } else if (hsv.hue < 240) {
      r = 0;
      g = x;
      b = c;
    } else if (hsv.hue < 300) {
      r = x;
      g = 0;
      b = c;
    } else {
      r = c;
      g = 0;
      b = x;
    }
    return rgb;
  }

  HSV rgbToHsv(RGB rgb) {
    HSV hsv;
    float r = rgb.red / 255.0;
    float g = rgb.green / 255.0;
    float b = rgb.blue / 255.0;
    float cmax = max(r, max(g, b));
    float cmin = min(r, min(g, b));
    float delta = cmax - cmin;
    if (delta == 0) {
      hsv.hue = 0;
    } else if (cmax == r) {
      hsv.hue = 60 * fmod((g - b) / delta, 6);
    } else if (cmax == g) {
      hsv.hue = 60 * ((b - r) / delta + 2);
    } else {
      hsv.hue = 60 * ((r - g) / delta + 4);
    }
    if (cmax == 0) {
      hsv.saturation = 0;
    } else {
      hsv.saturation = delta / cmax;
    }
    hsv.value = cmax;
    return hsv;
  }

}  // namespace Color
