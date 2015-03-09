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
     * @param double Joystick x value (-1.0 to 1.0)
     * @param double Joystick y value (-1.0 to 1.0)
     * @param double Joystick z value (-1.0 to 1.0)
     * @param double Sensitivity (0.0 to 1.0)
     * @param double Gyro value (unused)
     */
    void DriveMecanum(double, double, double, double, double);
    /**
     * @brief Drives the robot with arcade drive
     *
     * @param double Joystick x value (-1.0 to 1.0)
     * @param double Joystick y value (-1.0 to 1.0)
     */
    void DriveArcade(double, double);
    /**
     * @brief Tests one motor
     *
     * @param e_motors Motor to test
     * @param double Power to set motor
     */
    void TestMotor(e_motors, double);
};
#endif
// vim: ts=2:sw=2:et
