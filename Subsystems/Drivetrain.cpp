#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Commands/Drivetrain/Drive.h"

Drivetrain::Drivetrain(): Subsystem("Drivetrain"){
  rightFront = new Victor(DRIVE_FRONT_RIGHT);
  leftFront = new Victor(DRIVE_FRONT_LEFT);
  rightRear = new Victor(DRIVE_BACK_RIGHT);
  leftRear = new Victor(DRIVE_BACK_LEFT);
  gyro = new Gyro(DRIVE_GYRO_ANALOG);
}
void Drivetrain::InitDefaultCommand(){
  SetDefaultCommand(new Drive());
}
void Drivetrain::DriveMecanum(double x, double y, double z, double sensitivity, bool driveStraight){
  //TODO: Find the correct value for kP
  double kP=0.02;
  double correctX = -(sensitivity*(pow(x, 3))+(1-sensitivity)*x);
  double correctY = -(sensitivity*(pow(y, 3))+(1-sensitivity)*y);
  double correctZ;
  if(driveStraight){
    printf("Driving straight at: %f\n", -gyro->GetAngle()*kP);
    correctZ = -gyro->GetAngle()*kP;
  }else{
    correctZ = -z * 0.5;
  }
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
void Drivetrain::ResetGyro(){
  gyro->Reset();
}
// vim: ts=2:sw=2:et
