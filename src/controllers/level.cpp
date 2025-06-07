#include <Arduino.h>

#include "level.h"
#include "logging/logger.h"

namespace controllers {

sensors::HCSR04 *LevelController::getLevelSensor() { return this->levelSensor; }

actuators::OnOffValve *LevelController::getInletValve() {
  return this->inletValve;
}

leds::Led *LevelController::getErrorLed() { return this->errorLed; }

const float LevelController::getTankHeight() const { return this->tankHeight; }

const float LevelController::getMinLevel() const { return this->minLevel; }

const float LevelController::getMaxLevel() const { return this->maxLevel; }

const int LevelController::getMinPumpDuration() const {
  return this->minPumpDuration;
}

void LevelController::fatalError(const char *message) {
  this->getErrorLed()->On();
  this->getInletValve()->Close();

  logging::logger->Error(message);

  while (true) {
  }
}

LevelController::LevelController(sensors::HCSR04 *levelSensor,
                                 actuators::OnOffValve *inletValve,
                                 leds::Led *errorLed, const float tankHeight,
                                 const float minLevel, const float maxLevel,
                                 const int minPumpDuration)
    : levelSensor(levelSensor), inletValve(inletValve), errorLed(errorLed),
      tankHeight(tankHeight), minLevel(minLevel), maxLevel(maxLevel),
      minPumpDuration(minPumpDuration) {
  this->getErrorLed()->Off();
  this->getInletValve()->Close();

  if (this->getTankHeight() <= 0.0) {
    this->fatalError("Tank height must be greater than 0");
  }

  if (this->getMinLevel() <= 0.0) {
    this->fatalError("Min level must be greater than 0");
  }

  if (this->getMaxLevel() <= 0.0) {
    this->fatalError("Max level must be greater than 0");
  }

  if (this->getMinLevel() >= this->getTankHeight()) {
    this->fatalError("Min level must be less than tank height");
  }

  if (this->getMaxLevel() >= this->getTankHeight()) {
    this->fatalError("Max level must be less than tank height");
  }

  if (this->getMinLevel() >= this->getMaxLevel()) {
    this->fatalError("Min level must be less than max level");
  }
}

void LevelController::Handle() {
  // TODO: Implement the logic for the level controller
}

} // namespace controllers