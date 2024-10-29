/**
 * @file arm.c
 * @brief Implementation file for the robot controller tests
 *
 * This file provides the implementation for testing the Delta robot’s
 * safety mechanisms.
 *
 * @author Marco Rolón Radcenco
 * @date 2024-10-28
 * @version 1.0
 *
 * @note This file is part of the MIRA robot project test suite.
 */

#include "unity.h"
#include "robot_controller.h"
#include "arm.h"
#include "sensor.h"

/**
 * @brief Global robot object
 */
DeltaRobot_t robot;

/**
 * @brief Sets up the test environment before each test case.
 * Initializes the robot to a known state.
 */
void setUp(void)

{
    RobotController_Init(&robot);
}

/**
 * @brief Tears down the test environment after each test case.
 * Currently, no specific teardown is needed.
 */
void tearDown(void) {
}

/**
 * @brief Tests if the RobotController_Init function correctly sets the robot state to CALIBRATING.
 */
void test_RobotController_Init_Should_SetRobotToCalibrating(void) {
    TEST_ASSERT_EQUAL(ROBOT_STATE_CALIBRATING, robot.state);
}

/**
 * @brief Tests if the emergency button is checked correctly and returns false when pressed.
 */
void test_RobotController_CheckEmergencyButton_Should_ReturnFalseOnEmergency(void) {
    robot.sensors.emergency_button_pressed = true;
    bool safetyStatus = RobotController_CheckEmergencyButton(&robot.sensors);
    TEST_ASSERT_FALSE(safetyStatus);
}

/**
 * @brief Tests if limit switches are checked correctly and returns false when pressed.
 */
void test_RobotController_CheckLimitSwitches_Should_ReturnFalseOnLimitSwitchPressed(void) {
    robot.sensors.limit_switch_pressed[0] = true;
    bool safetyStatus = RobotController_CheckLimitSwitches(&robot.sensors);
    TEST_ASSERT_FALSE(safetyStatus);
}

/**
 * @brief Tests if the joint angles are checked correctly and returns false when invalid.
 */
void test_RobotController_CheckJointAngles_Should_ReturnFalseOnInvalidArmAngles_Minimum(void) {
    robot.arms[0].joint_angle = robot.arms[0].min_angle - 1.0f; // Invalid angle

    bool safetyStatus = RobotController_CheckJointAngles(robot.arms);
    TEST_ASSERT_FALSE(safetyStatus);
}

/**
 * @brief Tests if the joint angles are checked correctly and returns false when invalid.
 */
void test_RobotController_CheckJointAngles_Should_ReturnFalseOnInvalidArmAngles_Maximum(void) {
    robot.arms[0].joint_angle = robot.arms[0].max_angle + 1.0f; // Invalid angle

    bool safetyStatus = RobotController_CheckJointAngles(robot.arms);
    TEST_ASSERT_FALSE(safetyStatus);
}

/**
 * @brief Tests the overall robot safety check and returns true when all systems are safe.
 */
void test_RobotController_CheckRobotSafety_Should_ReturnTrueWhenSafe(void) {
    bool safetyStatus = RobotController_CheckRobotSafety(&robot.sensors, robot.arms, &robot.state);
    TEST_ASSERT_TRUE(safetyStatus);
    TEST_ASSERT_EQUAL(ROBOT_STATE_ACTIVE, robot.state);
}

/**
 * @brief Tests the overall robot safety check and returns false on emergency.
 */
void test_RobotController_CheckRobotSafety_Should_ReturnFalseOnEmergency(void) {
    robot.sensors.emergency_button_pressed = true;

    bool safetyStatus = RobotController_CheckRobotSafety(&robot.sensors, robot.arms, &robot.state);
    TEST_ASSERT_FALSE(safetyStatus);
    TEST_ASSERT_EQUAL(ROBOT_STATE_ERROR, robot.state);
}

/**
 * @brief Tests the overall robot safety check and returns false on limit switch pressed.
 */
void test_RobotController_CheckRobotSafety_Should_ReturnFalseOnLimitSwitchPressed(void) {
    robot.sensors.limit_switch_pressed[0] = true;

    bool safetyStatus = RobotController_CheckRobotSafety(&robot.sensors, robot.arms, &robot.state);
    TEST_ASSERT_FALSE(safetyStatus);
    TEST_ASSERT_EQUAL(ROBOT_STATE_ERROR, robot.state);
}

/**
 * @brief Tests the overall robot safety check and returns false on invalid arm angles.
 */
void test_RobotController_CheckRobotSafety_Should_ReturnFalseOnInvalidArmAngles_Minimum(void) {
    robot.arms[0].joint_angle = robot.arms[0].min_angle - 1.0f; // Invalid angle

    bool safetyStatus = RobotController_CheckRobotSafety(&robot.sensors, robot.arms, &robot.state);
    TEST_ASSERT_FALSE(safetyStatus);
    TEST_ASSERT_EQUAL(ROBOT_STATE_ERROR, robot.state);
}

/**
 * @brief Tests the overall robot safety check and returns false on invalid arm angles.
 */
void test_RobotController_CheckRobotSafety_Should_ReturnFalseOnInvalidArmAngles_Maximum(void) {
    robot.arms[0].joint_angle = robot.arms[0].max_angle + 1.0f; // Invalid angle

    bool safetyStatus = RobotController_CheckRobotSafety(&robot.sensors, robot.arms, &robot.state);
    TEST_ASSERT_FALSE(safetyStatus);
    TEST_ASSERT_EQUAL(ROBOT_STATE_ERROR, robot.state);
}
