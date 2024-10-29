#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include "arm.h"
#include "sensor.h"

/**
 * @brief Enumeration of the robot's operational states.
 *
 * This enumeration defines the various states the Delta Robot can be in.
 */
typedef enum {
    ROBOT_STATE_STOPPED,     /**< The robot is not in operation. */
    ROBOT_STATE_CALIBRATING, /**< The robot is in the calibration process. */
    ROBOT_STATE_ACTIVE,      /**< The robot is currently operating. */
    ROBOT_STATE_ERROR        /**< The robot has encountered an error. */
} RobotState_t;

/**
 * @brief Structure representing the Delta Robot.
 *
 * This structure holds all necessary components of the Delta Robot,
 * including its arms, end-effector, sensors, and current operational state.
 */
typedef struct {
    Arm_t arms[3];      /**< Array of three robotic arms. */
    Sensor_t sensors;   /**< Sensors module for checking emergency buttons and limit switches. */
    RobotState_t state; /**< The current operational state of the robot. */
} DeltaRobot_t;

// Public API

/**
 * @brief Initializes the robot controller.
 *
 * This function sets up the Delta Robot to its initial state. It should be called
 * before any operations are performed on the robot.
 *
 * @param robot Pointer to a DeltaRobot_t instance to be initialized.
 */
void RobotController_Init(DeltaRobot_t * robot);

/**
 * @brief Checks the emergency button status.
 *
 * This function checks the state of the emergency button. If the button is pressed,
 * it indicates a safety issue that prevents the robot from operating.
 *
 * @param sensors Pointer to the Sensor_t instance containing the emergency button state.
 * @return Returns true if the emergency button is not pressed; false if it is pressed.
 */
bool RobotController_CheckEmergencyButton(Sensor_t * sensors);

/**
 * @brief Checks the status of limit switches.
 *
 * This function checks the limit switches for the robot's arms. If any limit switch is pressed,
 * it indicates that the robot is in an unsafe condition.
 *
 * @param sensors Pointer to the Sensor_t instance containing the limit switch states.
 * @return Returns true if no limit switch is pressed; false if any limit switch is pressed.
 */
bool RobotController_CheckLimitSwitches(Sensor_t * sensors);

/**
 * @brief Checks the validity of arm joint angles.
 *
 * This function validates the joint angles of the robotic arms. Invalid angles can lead to
 * unsafe operation or damage to the robot.
 *
 * @param arms Pointer to an array of Arm_t instances to be checked.
 * @return Returns true if all arm angles are valid; false if any angle is invalid.
 */
bool RobotController_CheckJointAngles(Arm_t * arms);

/**
 * @brief Evaluates the overall safety of the robot.
 *
 * This function combines checks from the emergency button, limit switches, and arm angles
 * to determine if the robot is in a safe operating condition.
 *
 * @param sensors Pointer to the Sensor_t instance containing the states to be checked.
 * @param arms Pointer to an array of Arm_t instances to be validated.
 * @param state Pointer to the RobotState_t instance to be updated based on the safety evaluation.
 * @return Returns true if the robot is safe to operate; false if it is not.
 */
bool RobotController_CheckRobotSafety(Sensor_t * sensors, Arm_t * arms, RobotState_t * state);

#endif /* ROBOT_CONTROLLER_H */
