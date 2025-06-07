#ifndef HC_SR04_H
#define HC_SR04_H

namespace sensors {

class HCSR04 {
private:
  const unsigned int echoPin;
  const unsigned int triggerPin;

  const unsigned int getEchoPin() const;

  const unsigned int getTriggerPin() const;

public:
  HCSR04(unsigned int echoPin, unsigned int triggerPin);

  ~HCSR04();

  float Read();
};

} // namespace sensors

#endif