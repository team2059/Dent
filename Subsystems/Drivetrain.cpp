#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Commands/Drivetrain/Drive.h"

Drivetrain::Drivetrain(): Subsystem("Drivetrain") {
  rightRear = new CANTalon(DRIVE_BACK_RIGHT_CAN);
  leftRear = new CANTalon(DRIVE_BACK_LEFT_CAN);
  gyro = new Gyro(DRIVE_GYRO_ANALOG);
}
void Drivetrain::InitDefaultCommand() {
  SetDefaultCommand(new Drive());
}
void Drivetrain::DriveArcade(double x, double y, double z, double sensitivity, bool driveStraight) {
  //TODO add encoder support for driving straight
  leftRear->Set(-y+(x+z));
  rightRear->Set(y+(x+z));
}
//Used in pretest
void Drivetrain::TestMotor(e_motors motor, double power) {
  switch(motor) {
    case BACKRIGHT:
      rightRear->Set(power);
      break;
    case BACKLEFT:
      leftRear->Set(power);
      break;
    default:
      break;
  }
}
void Drivetrain::ResetGyro() {
  gyro->Reset();
}
// vim: ts=2:sw=2:et
