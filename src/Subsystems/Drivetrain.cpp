#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain"){
  frontLeft=new CANTalon(40);
  frontRight=new CANTalon(41);
  backLeft=new CANTalon(42);
  backRight=new CANTalon(43);
  drive=new RobotDrive(frontLeft, frontRight, backLeft, backRight);
}
void Drivetrain::InitDefaultCommand(){
  SetDefaultCommand(new Drive());
}
void Drivetrain::DriveMecanum(float x, float y, float rotation){
  drive->MecanumDrive_Cartesian(x, y, rotation);
}
void Drivetrain::DriveArcade(float x, float y){
  drive->ArcadeDrive(x, y);
}
