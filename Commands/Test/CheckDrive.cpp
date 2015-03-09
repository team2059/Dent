#include "CheckDrive.h"
#include <cmath>
#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
#include "../../RobotMap.h"
CheckDrive::CheckDrive(int motorID): CommandGroup("CheckDrive"){
  Requires(DentRobot::drivetrain);
  motor = motorID;
}
void CheckDrive::Initialize(){
  SetTimeout(1.0);
}
void CheckDrive::Execute(){
  switch(motor){
    case DRIVE_FRONT_LEFT:
      DentRobot::drivetrain->TestMotor(DentRobot::drivetrain->FRONTLEFT, 1);
      break;
    case DRIVE_FRONT_RIGHT:
      DentRobot::drivetrain->TestMotor(DentRobot::drivetrain->FRONTRIGHT, 1);
      break;
    case DRIVE_BACK_LEFT:
      DentRobot::drivetrain->TestMotor(DentRobot::drivetrain->BACKLEFT, 1);
      break;
    case DRIVE_BACK_RIGHT:
      DentRobot::drivetrain->TestMotor(DentRobot::drivetrain->BACKRIGHT, 1);
      break;
    default:
      break;
  }
}
bool CheckDrive::IsFinished(){
  return false;
}
void CheckDrive::End(){
}
void CheckDrive::Interrupted(){
  End();
}
