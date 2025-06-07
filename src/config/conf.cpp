#include "conf.h"

namespace config {

const unsigned long DEFAULT_BAUD_RATE = 115200;

const unsigned int BUILTIN_LED_PIN = 13;

const unsigned int HC_SR04_ECHO_PIN = 3;

const unsigned int HC_SR04_TRIGGER_PIN = 2;

const unsigned int INLET_VALVE_PIN = 4;

const float TANK_HEIGHT_MM = 100.0;

const float MIN_LEVEL_MM = 20.0;

const float MAX_LEVEL_MM = 80.0;

const int MIN_PUMP_DURATION_MS = 3000;

} // namespace config