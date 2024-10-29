/**
 * @file sensor.c
 * @brief Implementation file for the sensor module
 *
 * This file contains the functions for initializing and managing the
 * sensors used in the Delta robot. It includes functions for checking
 * the state of the emergency button and the limit switches.
 *
 * @author Marco Rolón Radcenco
 * @date 2024-10-28
 * @version 1.0
 *
 * @note This file is part of the MIRA robot project.
 *
 */

#include "sensor.h"

void Sensor_Init(Sensor_t * sensor) {
    sensor->emergency_button_pressed = false;
    for (int i = 0; i < 3; ++i) {
        sensor->limit_switch_pressed[i] = false;
    }
}

bool Sensor_CheckEmergencyButton(Sensor_t * sensor) {
    // @todo implement port reading
    return sensor->emergency_button_pressed;
}

bool Sensor_CheckLimitSwitches(Sensor_t * sensor) {
    for (int i = 0; i < 3; ++i) {
        // @todo implement port reading
        if (sensor->limit_switch_pressed[i]) {
            return true;
        }
    }
    return false;
}
