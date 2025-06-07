#include <Arduino.h>

#include "config/conf.h"
#include "controllers/level.h"
#include "io/actuators/valves.h"
#include "io/leds/leds.h"
#include "io/sensors/hc_sr04.h"
#include "logging/logger.h"

leds::Led *builtinLed;
actuators::OnOffValve *inletValve;
sensors::HCSR04 *levelSensor;
controllers::LevelController *levelController;

void setup() {
  logging::logger->Initialize();
  logging::logger->Info("Setting up system");

  builtinLed = new leds::Led(config::BUILTIN_LED_PIN);
  inletValve = new actuators::OnOffValve(config::INLET_VALVE_PIN);
  levelSensor = new sensors::HCSR04(config::HC_SR04_ECHO_PIN,
                                    config::HC_SR04_TRIGGER_PIN);

  levelController = new controllers::LevelController(
      levelSensor, inletValve, builtinLed, config::TANK_HEIGHT_MM,
      config::MIN_LEVEL_MM, config::MAX_LEVEL_MM, config::MIN_PUMP_DURATION_MS);

  logging::logger->Info("System initialized successfully");
}

void loop() {
  logging::logger->Info("Loop iteration started");

  levelController->Handle();

  logging::logger->Info("Loop iteration finished");
}
