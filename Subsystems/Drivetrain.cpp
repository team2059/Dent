#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain"){
  rightFront = new CANTalon(DRIVE_FRONT_RIGHT_CAN);
  leftFront = new CANTalon(DRIVE_FRONT_LEFT_CAN);
  rightRear = new CANTalon(DRIVE_BACK_RIGHT_CAN);
  leftRear = new CANTalon(DRIVE_BACK_LEFT_CAN);
}
void Drivetrain::InitDefaultCommand(){
  SetDefaultCommand(new Drive());
}
void Drivetrain::DriveMecanum(float x, float y, float z, float sensitivity, float gyro){
  double correctY = (sensitivity*(pow(y,3))+(1-sensitivity)*y);
  double correctX = -(sensitivity*(pow(x,3))+(1-sensitivity)*x);
  double correctZ = -z *.5;
  rightFront->Set((-correctX + correctY - correctZ));
  leftFront->Set((correctX + correctY + correctZ)*-1);
  rightRear->Set((correctX + correctY - correctZ));
  leftRear->Set((-correctX + correctY + correctZ)*-1);
}
