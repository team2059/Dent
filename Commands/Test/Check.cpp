#include "Check.h"
#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
#include "../../RobotMap.h"
#include "CheckDrive.h"
Check::Check(){
  AddSequential(new CheckDrive(DRIVE_FRONT_LEFT_CAN));
  AddSequential(new CheckDrive(DRIVE_FRONT_RIGHT_CAN));
  AddSequential(new CheckDrive(DRIVE_BACK_LEFT_CAN));
  AddSequential(new CheckDrive(DRIVE_BACK_RIGHT_CAN));
}
