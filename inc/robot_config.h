/**
 * @file robot_config.h
 * @brief Configuration file for robot parameters
 *
 * This file defines the joint limits for the Delta robot's
 * arms. It includes the minimum and maximum angles that each
 * joint can assume during operation.
 *
 * @author Marco Rolón Radcenco
 * @date 2024-10-28
 * @version 1.0
 *
 * @note This file is part of the MIRA robot project.
 */

#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

// Joint limits
#define ROBOT_MIN_JOINT_ANGLE 0.0f  /**< Minimum joint angle (in degrees) for the robotic arms. */
#define ROBOT_MAX_JOINT_ANGLE 90.0f /**< Maximum joint angle (in degrees) for the robotic arms. */

#endif // ROBOT_CONFIG_H
