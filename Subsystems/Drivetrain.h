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
    Talon *rightFront, //<! Front right motor
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
    void DriveMecanum(double x, double y, double z);
    /**
     * @brief Sets the gyro value to 0.0
     */
    void ResetGyro();
};
#endif
// vim: ts=2:sw=2:et
