#include <Arduino.h>
#include "settings.h"
#include "log.h"
#include "color.h"
#include "rainbow.h"
#include "analogpin.h"
#include "dummy.h"
#include "controlmode.h"

namespace cm = controlmode;

const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

const int analogControlRedPin = A0;
const int analogControlGreenPin = A1;
const int analogControlBluePin = A2;


cm::ControlMode controlMode = NONE;
uint64_t availableControlModes = NONE;
long lastInfo = 0;


uint64_t getAvailableControlModes() {
  modes = 0;
  #if ENABLE_DUMMY_CONTROL
    modes |= DUMMY;
  #endif
  #if ENABLE_RAINBOW_CONTROL
    modes |= RAINBOW;
  #endif
  #if ENABLE_ANALOG_PIN_CONTROL
    modes |= ANALOG_PIN;
  #endif
  #if ENABLE_ETHERNET_CONTROL
    modes |= ETHERNET;
  #endif
  return modes;
}


color::RGB fetchColor() {
  switch (mode) {
    case DUMMY:
      return cm::fetchDummyColor();
    case RAINBOW:
      return cm::fetchRainbowColor();
    case ANALOG_PIN:
      return cm::fetchAnalogPinColor();
    case ETHERNET:
      return cm::fetchEthernetColor();
  }
}


void selectFirstControlMode() {
  for (int i = 0; i < 64; i++) {
    if (availableControlModes & (1ULL << i)) {
      controlMode = 1ULL << i;
      return;
    }
  }
}


void setup() {
  availableControlModes = getAvailableControlModes();
  selectFirstControlMode();
  log.setup();
}


void maybePrintInfo() {
  if (millis() - lastInfo > 1000) {
    log::info("Current color");
    log::extra("Red: " + String(red));
    log::extra("Green: " + String(green));
    log::extra("Blue: " + String(blue));
    lastInfo = millis();
  }
}


void loop() {
  color::RGB c = fetchColor();
  maybePrintInfo();
  updateLeds(c);
  delay(100);
}


void updateLeds(color::RGB c) {
  analogWrite(redPin, c.red);
  analogWrite(greenPin, c.green);
  analogWrite(bluePin, c.blue);
}

