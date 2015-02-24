#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
#include "../../RobotMap.h"
#include "../Elevator/Raise.h"
#include "CheckRobot.h"
#include "CheckDrive.h"
CheckRobot::CheckRobot(){
  AddSequential(new CheckDrive(DRIVE_FRONT_LEFT_CAN));
  AddSequential(new CheckDrive(DRIVE_FRONT_RIGHT_CAN));
  AddSequential(new CheckDrive(DRIVE_BACK_LEFT_CAN));
  AddSequential(new CheckDrive(DRIVE_BACK_RIGHT_CAN));
}
// vim: ts=2:sw=2:et