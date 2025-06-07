#ifndef LEVEL_H
#define LEVEL_H

#include "../io/actuators/valves.h"
#include "../io/leds/leds.h"
#include "../io/sensors/hc_sr04.h"

namespace controllers {

class LevelController {
private:
  sensors::HCSR04 *levelSensor;
  actuators::OnOffValve *inletValve;
  leds::Led *errorLed;
  const float tankHeight;
  const float minLevel;
  const float maxLevel;
  const int minPumpDuration;

  sensors::HCSR04 *getLevelSensor();

  actuators::OnOffValve *getInletValve();

  leds::Led *getErrorLed();

  const float getTankHeight() const;

  const float getMinLevel() const;

  const float getMaxLevel() const;

  const int getMinPumpDuration() const;

  void fatalError();

public:
  LevelController(sensors::HCSR04 *levelSensor,
                  actuators::OnOffValve *inletValve, leds::Led *errorLed,
                  const float tankHeight, const float minLevel,
                  const float maxLevel, const int minPumpDuration);

  ~LevelController();

  void Handle();
};

} // namespace controllers

#endif