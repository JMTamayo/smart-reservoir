#include <Arduino.h>

#include "valves.h"

namespace actuators {

const unsigned long OnOffValve::getPin() const { return this->pin; }

OnOffValve::OnOffValve(unsigned long pin) : pin(pin) {
  pinMode(this->getPin(), OUTPUT);
  digitalWrite(this->getPin(), LOW);
}

OnOffValve::~OnOffValve() {}

void OnOffValve::Open() { digitalWrite(this->getPin(), HIGH); }

void OnOffValve::Close() { digitalWrite(this->getPin(), LOW); }

} // namespace actuators