#include "Autonomous.h"
#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
#include ""
Autonomous::Autonomous(){
  AddSequential(new AutoDrive());
}
