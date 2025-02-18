#pragma once


namespace log {

    void setup() {
      Serial.begin(9600);
    }


    void info(String message) {
      Serial.println(
        String("[INFO] ")
        + message
      );
    }


    void info(const char *message) {
      info(String(message));
    }


    void extra(String message) {
      Serial.println(
        String("    ")
        + message
      );
    }


    void extra(const char *message) {
      extra(String(message));
    }


}  // namespace util
