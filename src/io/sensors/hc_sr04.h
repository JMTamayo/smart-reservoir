#ifndef HC_SR04_H
#define HC_SR04_H

namespace sensors {

class HCSR04 {
private:
  const unsigned long echoPin;
  const unsigned long triggerPin;

  const unsigned long getEchoPin() const;

  const unsigned long getTriggerPin() const;

public:
  HCSR04();

  ~HCSR04();

  float Read();
};

} // namespace sensors

#endif