#include "Autonomous.h"
#include "AutoDrive.h"
#include "../../DentRobot.h"
#include "../Elevator/Raise.h"
Autonomous::Autonomous(){
  AddSequential(new AutoDrive());
  AddSequential(new Raise());
}
// vim: ts2:sw=2:et
