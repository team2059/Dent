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
  double kP = SmartDashboard::GetNumber("Gyro kP");
  double correctX = -(sensitivity*(pow(x, 3))+(1-sensitivity)*x);
  double correctY = -(sensitivity*(pow(y, 3))+(1-sensitivity)*y);
  double correctZ = z;
  if(driveStraight) {
    printf("Driving straight at: %f\n", -gyro->GetAngle()*kP);
    correctZ = -gyro->GetAngle()*kP;
  } else {
    correctZ = -z * 0.5;
  }

  if(DentRobot::oi->GetLeftStick()->GetRawButton(9)) {
    correctY /= 2.0;
  }
  int leftPower=((correctY+(correctX+correctZ))/2+1)*127+1;
  int rightPower=((correctY-(correctX+correctZ))/2+1)*127+1;
  printf("rightPower:%d\n",rightPower);
  printf("leftPower:%d\n",leftPower);
  leftRear->Set(leftPower);
  rightRear->Set(rightPower);
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
