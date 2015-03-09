#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Commands/Drivetrain/Drive.h"

Drivetrain::Drivetrain(): Subsystem("Drivetrain"){
  rightFront = new CANTalon(DRIVE_FRONT_RIGHT_CAN);
  leftFront = new CANTalon(DRIVE_FRONT_LEFT_CAN);
  rightRear = new CANTalon(DRIVE_BACK_RIGHT_CAN);
  leftRear = new CANTalon(DRIVE_BACK_LEFT_CAN);
}
void Drivetrain::InitDefaultCommand(){
  SetDefaultCommand(new Drive());
}
void Drivetrain::DriveMecanum(double x, double y, double z, double sensitivity, double gyro){
  double correctX = -(sensitivity*(pow(x, 3))+(1-sensitivity)*x);
  double correctY = -(sensitivity*(pow(y, 3))+(1-sensitivity)*y);
  double correctZ = -z * 0.5;
  if(DentRobot::oi->GetLeftStick()->GetRawButton(9)){
    correctY /= SmartDashboard::GetNumber("DriveSpeedReductionThresh");
  }
  rightFront->Set((-correctX + correctY - correctZ));
  leftFront->Set((correctX + correctY + correctZ)*-1);
  rightRear->Set((correctX + correctY - correctZ));
  leftRear->Set((-correctX + correctY + correctZ)*-1);
}

//Used in pretest
void Drivetrain::TestMotor(e_motors motor, double power){
  switch(motor){
    case FRONTRIGHT:
      rightFront->Set(power);
      break;
    case FRONTLEFT:
      leftFront->Set(power);
      break;
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
// vim: ts=2:sw=2:et
