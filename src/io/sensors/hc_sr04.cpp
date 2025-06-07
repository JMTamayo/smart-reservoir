#include <Arduino.h>

#include "../../config/conf.h"
#include "hc_sr04.h"

namespace sensors {

const unsigned int HCSR04::getEchoPin() const { return this->echoPin; }

const unsigned int HCSR04::getTriggerPin() const { return this->triggerPin; }

HCSR04::HCSR04(unsigned int echoPin, unsigned int triggerPin)
    : echoPin(echoPin), triggerPin(triggerPin) {
  pinMode(this->getTriggerPin(), OUTPUT);
  pinMode(this->getEchoPin(), INPUT);
  digitalWrite(this->getTriggerPin(), LOW);
}

HCSR04::~HCSR04() {}

float HCSR04::Read() {
  digitalWrite(this->getTriggerPin(), HIGH);
  delayMicroseconds(20);
  digitalWrite(this->getTriggerPin(), LOW);

  long duration = pulseIn(this->getEchoPin(), HIGH);

  float distance = (duration * 0.343) / 2.0;

  return distance;
}

} // namespace sensors