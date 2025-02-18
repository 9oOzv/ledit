#pragma once

namespace control {


    enum ControlMode {
      NONE = 0,
      DUMMY = 1ULL << 0,
      RAINBOW = 1ULL << 1,
      ANALOG_PIN = 1ULL << 2,
      ETHERNET = 1ULL << 3
    };


} // namespace control
