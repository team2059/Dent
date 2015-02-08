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
    void DriveMecanum(float,float,float,float,float);
    void DriveArcade(float, float);
    void TestMotor(e_motors,float);
};
#endif
// vim: ts2:sw=2:et
