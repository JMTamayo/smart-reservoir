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

void LevelController::fatalError() {
  this->getErrorLed()->On();
  this->getInletValve()->Close();

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
    logging::logger->Error("Tank height must be greater than 0");
    this->fatalError();
  }

  if (this->getMinLevel() <= 0.0) {
    logging::logger->Error("Min level must be greater than 0");
    this->fatalError();
  }

  if (this->getMaxLevel() <= 0.0) {
    logging::logger->Error("Max level must be greater than 0");
    this->fatalError();
  }

  if (this->getMinLevel() >= this->getTankHeight()) {
    logging::logger->Error("Min level must be less than tank height");
    this->fatalError();
  }

  if (this->getMaxLevel() >= this->getTankHeight()) {
    logging::logger->Error("Max level must be less than tank height");
    this->fatalError();
  }

  if (this->getMinLevel() >= this->getMaxLevel()) {
    logging::logger->Error("Min level must be less than max level");
    this->fatalError();
  }
}

void LevelController::Handle() {
  // TODO: Implement the logic for the level controller
}

} // namespace controllers