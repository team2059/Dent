#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
class Drivetrain: public Subsystem{
  private:
    CANTalon *rightFront, *leftFront, *rightRear, *leftRear;
    RobotDrive *drive;
  public:
    Drivetrain();
    void InitDefaultCommand();
    void DriveMecanum(float,float,float,float,float);
    void DriveArcade(float, float);
};
#endif
