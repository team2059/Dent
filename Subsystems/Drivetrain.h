#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
/**
 * @brief Drives the robot
 * 
 * 4 wheel mecanum drive
 */
class Drivetrain: public Subsystem{
  private:
    CANTalon *rightFront, //<! Front right motor
             *leftFront, //<! Front left motor
             *rightRear, //<! Back right motor
             *leftRear; //<! Back left motor
    Gyro *gyro; //<! Gyro
  public:
    /**
     * @brief Constructs Drivetrain
     */
    Drivetrain();
    /**
     * @brief Current motor to test
     */
    enum e_motors{
      FRONTRIGHT, //<! Front right motor
      FRONTLEFT, //<! Front left motor
      BACKRIGHT, //<! Back right motor
      BACKLEFT //<! Back left motor
    };
    /**
     * @brief No action
     */
    void InitDefaultCommand();
    /**
     * @brief Drives the robot with mecanum
     *
     * @param x Joystick x value (-1.0 to 1.0)
     * @param y Joystick y value (-1.0 to 1.0)
     * @param z Joystick z value (-1.0 to 1.0)
     * @param sensitivity Sensitivity (0.0 to 1.0)
     * @param driveStraight Overrides z value to correct for motor lag
     */
    void DriveMecanum(double x, double y, double z, double sensitivity, bool driveStraight=false);
    /**
     * @brief Tests one motor
     *
     * @param motor Motor to test
     * @param power Power to set motor
     */
    void TestMotor(e_motors motor, double power);
    /**
     * @brief Sets the gyro value to 0.0
     */
    void ResetGyro();
};
#endif
// vim: ts=2:sw=2:et
