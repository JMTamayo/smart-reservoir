#include <Arduino.h>

#include "../../config/conf.h"
#include "leds.h"

namespace leds {

const unsigned long Led::getPin() const { return this->pin; }

Led::Led() : pin(config::BUILTIN_LED_PIN) {
  pinMode(this->getPin(), OUTPUT);
  digitalWrite(this->getPin(), LOW);
}

Led::~Led() {}

void Led::Toggle() {
  digitalWrite(this->getPin(), !digitalRead(this->getPin()));
}

} // namespace leds