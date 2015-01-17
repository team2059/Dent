#include "Drivetrain.h"
#include "../RobotMap.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
  frontLeft=new Talon(0);
  frontRight=new Talon(1);
  backLeft=new Talon(2);
  backRight=new Talon(3);
  drive=new RobotDrive(frontLeft, frontRight, backLeft, backRight);
}
void Drivetrain::InitDefaultCommand() {
}
void Drivetrain::DriveMecanum(float x, float y, float rotation){
  drive->MecanumDrive_Cartesian(x, y, rotation);
}
void Drivetrain::DriveArcade(float x, float y){
  drive->ArcadeDrive(x, y);
}
