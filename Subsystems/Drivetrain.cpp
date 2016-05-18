#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Commands/Drivetrain/Drive.h"

Drivetrain::Drivetrain(): Subsystem("Drivetrain"){
  rightFront = new Talon(DRIVE_FRONT_RIGHT_CAN);
  leftFront = new Talon(DRIVE_FRONT_LEFT_CAN);
  rightRear = new Talon(DRIVE_BACK_RIGHT_CAN);
  leftRear = new Talon(DRIVE_BACK_LEFT_CAN);
  gyro = new Gyro(DRIVE_GYRO_ANALOG);
}
void Drivetrain::InitDefaultCommand(){
  SetDefaultCommand(new Drive());
}
void Drivetrain::DriveMecanum(double x, double y, double z){
  printf("Driving: %f,%f,%f",x,y,z);
  printf("Right: %f",(y+(x+z)));
  printf("Left: %f",(-y+(x+z)));
  rightFront->Set(y+(x+z));
  rightRear->Set(y+(x+z));
  leftFront->Set(-y+(x+z));
  leftRear->Set(-y+(x+z));
}
void Drivetrain::ResetGyro(){
  gyro->Reset();
}
// vim: ts=2:sw=2:et
