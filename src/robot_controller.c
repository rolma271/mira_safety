/**
 * @file robot_controller.c
 * @brief Robot controller implementation
 *
 * This file contains functions for initializing the robot controller,
 * checking the robot's safety status, and managing the robotic arms.
 *
 * @author Marco Rolón Radcenco
 * @date 2024-10-28
 * @version 1.0
 *
 * @note This implementation is part of the MIRA robot project.
 */

#include "robot_controller.h"
#include "arm.h"
#include "sensor.h"

void RobotController_Init(DeltaRobot_t * robot) {
    robot->state = ROBOT_STATE_CALIBRATING;
    Arms_Init(robot->arms); // Reset arm positions
    Sensor_Init(&robot->sensors);
}

// Check if the robot is safe based on emergency button
bool RobotController_CheckEmergencyButton(Sensor_t * sensors) {
    if (Sensor_CheckEmergencyButton(sensors)) {
        return false; // Emergency button pressed
    }
    return true; // No emergency
}

// Check limit switches
bool RobotController_CheckLimitSwitches(Sensor_t * sensors) {
    if (Sensor_CheckLimitSwitches(sensors)) {
        return false; // Limit switch pressed
    }
    return true; // All limits safe
}

// Check arm angles
bool RobotController_CheckJointAngles(Arm_t * arms) {
    return Arm_CheckJointAngles(arms); // All angles valid
}

// Check the safety of the robot
bool RobotController_CheckRobotSafety(Sensor_t * sensors, Arm_t * arms, RobotState_t * state) {
    if (!RobotController_CheckEmergencyButton(sensors)) {
        *state = ROBOT_STATE_ERROR; // Set state to error
        return false;               // Not safe
    }
    if (!RobotController_CheckLimitSwitches(sensors)) {
        *state = ROBOT_STATE_ERROR; // Set state to error
        return false;               // Not safe
    }
    if (!RobotController_CheckJointAngles(arms)) {
        *state = ROBOT_STATE_ERROR; // Set state to error
        return false;               // Not safe
    }
    *state = ROBOT_STATE_ACTIVE; // Set state to active
    return true;                 // Safe
}
