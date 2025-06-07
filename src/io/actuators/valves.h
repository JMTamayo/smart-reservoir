#ifndef VALVES_H
#define VALVES_H

namespace actuators {

class OnOffValve {
private:
  const unsigned long pin;

  const unsigned long getPin() const;

public:
  OnOffValve(unsigned long pin);

  ~OnOffValve();

  void Open();

  void Close();
};

} // namespace actuators

#endif