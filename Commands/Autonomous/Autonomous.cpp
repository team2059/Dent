#include "Autonomous.h"
#include "AutoDrive.h"
#include "../../DentRobot.h"
#include "../Elevator/Raise.h"
Autonomous::Autonomous(){
  AddSequential(new AutoDrive());
}
