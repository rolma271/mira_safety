/**
 * @file arm.c
 * @brief Implementation file for robotic arm control
 *
 * This file provides the implementation for managing the Delta robot’s
 * arms. It includes functions for initializing the arms, setting joint
 * angles, and validating joint angles against defined limits.
 *
 * @author Marco Rolón Radcenco
 * @date 2024-10-28
 * @version 1.0
 *
 * @note This file is part of the MIRA robot project.
 */

#include "arm.h"
#include "robot_config.h"

void Arms_Init(Arm_t arms[3]) {
    for (int i = 0; i < 3; ++i) {
        Arm_SetAngle(&arms[i], 0.0f); // Initialize each arm's joint angle to zero
    }
    for (int i = 0; i < 3; ++i) {
        arms[i].min_angle = ROBOT_MIN_JOINT_ANGLE; // Initialize each arm's minimum joint angle
    }
    for (int i = 0; i < 3; ++i) {
        arms[i].max_angle = ROBOT_MAX_JOINT_ANGLE; // Initialize each arm's maximum joint angle
    }
}

void Arm_SetAngle(Arm_t * arm, float angle) {
    arm->joint_angle = angle; // @todo: improve implementation, check validity, etc
}

bool Arm_CheckJointAngles(const Arm_t arms[3]) {
    for (int i = 0; i < 3; ++i) {
        if (arms[i].joint_angle < arms[i].min_angle || arms[i].joint_angle > arms[i].max_angle) {
            return false;
        }
    }
    return true;
}
