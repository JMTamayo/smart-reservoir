#include <Arduino.h>

#include "../../config/conf.h"
#include "leds.h"

namespace leds {

const unsigned long Led::getPin() const { return this->pin; }

Led::Led(unsigned long pin) : pin(pin) {
  pinMode(this->getPin(), OUTPUT);
  digitalWrite(this->getPin(), LOW);
}

Led::~Led() {}

void Led::On() { digitalWrite(this->getPin(), HIGH); }

void Led::Off() { digitalWrite(this->getPin(), LOW); }

} // namespace leds