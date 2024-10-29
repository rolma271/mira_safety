/**
 * @file arm.h
 * @brief Header file for the robotic arm management
 *
 * This file defines the structure and functions for controlling
 * the robotic arms of the Delta robot, including setting angles
 * and checking joint angle validity.
 *
 * @author Marco Rolón Radcenco
 * @date 2024-10-28
 * @version 1.0
 *
 * @note This file is part of the MIRA robot project.
 */

#ifndef ARM_H
#define ARM_H

#include <stdbool.h>

/**
 * @brief Structure representing a robotic arm.
 *
 * This structure contains the joint angle of the arm along with its
 * minimum and maximum allowable angles, which define the movement
 * range of the arm.
 */
typedef struct {
    float joint_angle; /**< Current angle of the joint in degrees. */
    float min_angle;   /**< Minimum allowable angle for the joint in degrees. */
    float max_angle;   /**< Maximum allowable angle for the joint in degrees. */
} Arm_t;

// Public API

/**
 * @brief Initializes the robotic arms.
 *
 * This function sets the initial angles of the robotic arms to a default value,
 * typically the minimum angle, and prepares them for operation.
 * It should be called before using the arms in any robot functionality.
 *
 * @param arms Array of Arm_t instances representing the robotic arms to be initialized.
 */
void Arms_Init(Arm_t arms[3]);

/**
 * @brief Sets the angle of a specified robotic arm.
 *
 * This function adjusts the joint angle of a specified arm to a given value,
 * ensuring that the new angle is within the defined range of allowable angles.
 *
 * @param arm Pointer to the Arm_t instance to be adjusted.
 * @param angle The target angle to set for the arm's joint in degrees.
 */
void Arm_SetAngle(Arm_t * arm, float angle);

/**
 * @brief Checks the validity of the joint angles of all robotic arms.
 *
 * This function evaluates the joint angles of the specified arms to ensure
 * they are within their defined limits. If any arm's angle is out of range,
 * the function returns false, indicating a safety issue.
 *
 * @param arms Array of Arm_t instances representing the robotic arms to be checked.
 * @return Returns true if all arm angles are valid; false if any angle is invalid.
 */
bool Arm_CheckJointAngles(const Arm_t arms[3]);

#endif // ARM_H
