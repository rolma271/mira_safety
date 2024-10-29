/**
 * @file sensor.h
 * @brief Header file for the sensor module
 *
 * This file defines the structure and functions for managing
 * the sensors used in the Delta robot, including the emergency
 * button and limit switches.
 *
 * @author Marco Rolón Radcenco
 * @date 2024-10-28
 * @version 1.0
 *
 * @note This file is part of the MIRA robot project.
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <stdbool.h>

/**
 * @brief Structure representing the sensors used in the robot.
 *
 * This structure contains the state of the emergency button and limit switches
 * for monitoring the robot's safety.
 */
typedef struct {
    bool emergency_button_pressed; /**< Indicates if the emergency button has been pressed. */
    bool limit_switch_pressed[3];  /**< Array indicating the status of three limit switches. */
} Sensor_t;

// Public API

/**
 * @brief Initializes the sensors.
 *
 * This function sets the initial state of the sensors, preparing them for use.
 * It should be called before any other sensor operations to ensure they are
 * correctly initialized.
 *
 * @param sensor Pointer to a Sensor_t instance to be initialized.
 */
void Sensor_Init(Sensor_t * sensor);

/**
 * @brief Checks the status of the emergency button.
 *
 * This function evaluates the state of the emergency button. If the button is pressed,
 * it indicates a safety issue that may require immediate action to halt robot operations.
 *
 * @param sensor Pointer to the Sensor_t instance containing the emergency button state.
 * @return Returns true if the emergency button is not pressed; false if it is pressed.
 */
bool Sensor_CheckEmergencyButton(Sensor_t * sensor);

/**
 * @brief Checks the status of the limit switches.
 *
 * This function evaluates the states of the limit switches associated with the robot's arms.
 * If any limit switch is pressed, it indicates that the robot may be in an unsafe position.
 *
 * @param sensor Pointer to the Sensor_t instance containing the limit switch states.
 * @return Returns true if none of the limit switches are pressed; false if any limit switch is
 * pressed.
 */
bool Sensor_CheckLimitSwitches(Sensor_t * sensor);

#endif // SENSOR_H
