#pragma once

namespace config {

// Serial Configuration parameters:
extern const unsigned long DEFAULT_BAUD_RATE; // Default baud rate for serial
                                              // communication

// I/O Pin Labeling:
extern const unsigned long
    BUILTIN_LED_PIN; // Built-in LED pin for microcontroller
extern const unsigned long HC_SR04_ECHO_PIN; // Echo pin for HC-SR04 sensor
extern const unsigned long
    HC_SR04_TRIGGER_PIN; // Trigger pin for HC-SR04 sensor

} // namespace config