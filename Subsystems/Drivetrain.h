#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
class Drivetrain: public Subsystem{
  private:
    CANTalon *rightFront, *leftFront, *rightRear, *leftRear;
    RobotDrive *drive;
  public:
    Drivetrain();
    enum e_motors{
      FRONTRIGHT,
      FRONTLEFT,
      BACKRIGHT,
      BACKLEFT
    };
    void InitDefaultCommand();
    void DriveMecanum(double, double, double, double, double);
    void DriveArcade(double, double);
    void TestMotor(e_motors, double);
};
#endif
// vim: ts=2:sw=2:et
