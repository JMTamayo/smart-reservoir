#include <Arduino.h>

#include "io/leds/leds.h"
#include "logging/logger.h"

leds::Led *builtinLed;

void setup() {
  logging::logger->Initialize();

  logging::logger->Info("System initialized");
  builtinLed = new leds::Led();
}

void loop() {
  logging::logger->Info("Builtin LED toggled");
  builtinLed->Toggle();
  delay(3000);
}
