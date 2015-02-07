#include "Autonomous.h"
#include "AutoDrive.h"
#include "../../DentRobot.h"
Autonomous::Autonomous(){
  AddSequential(new AutoDrive());
}
