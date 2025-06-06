#include <Arduino.h>

#include "../../config/conf.h"
#include "hc_sr04.h"

namespace sensors {

const unsigned long HCSR04::getEchoPin() const { return this->echoPin; }

const unsigned long HCSR04::getTriggerPin() const { return this->triggerPin; }

HCSR04::HCSR04()
    : echoPin(config::HC_SR04_ECHO_PIN),
      triggerPin(config::HC_SR04_TRIGGER_PIN) {
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