#pragma once

namespace config {

// Serial Configuration parameters:
extern const unsigned long DEFAULT_BAUD_RATE; // Default baud rate for serial
                                              // communication

// I/O Pin Labeling:
extern const unsigned int
    BUILTIN_LED_PIN; // Built-in LED pin for microcontroller

extern const unsigned int HC_SR04_ECHO_PIN;    // Echo pin for HC-SR04 sensor
extern const unsigned int HC_SR04_TRIGGER_PIN; // Trigger pin for HC-SR04 sensor

extern const unsigned int INLET_VALVE_PIN; // Pin for the inlet valve

extern const float TANK_HEIGHT_MM;     // Height of the tank in mm
extern const float MIN_LEVEL_MM;       // Minimum level of the tank in mm
extern const float MAX_LEVEL_MM;       // Maximum level of the tank in mm
extern const int MIN_PUMP_DURATION_MS; // Minimum pump duration in ms

} // namespace config