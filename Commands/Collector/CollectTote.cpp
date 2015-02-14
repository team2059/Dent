#include "CollectTote.h"
#include "../../DentRobot.h"
#include "../Autonomous/AutoDrive.h"
#include "RollIn.h"
CollectTote::CollectTote(){
  AddParallel(new AutoDrive(0.5, -1.0));
  AddSequential(new RollIn());
  AddParallel(new AutoDrive(0.5, 1.0));
  AddSequential(new RollIn());
  AddParallel(new AutoDrive(0.5, -1.0));
  AddSequential(new RollIn());
}
// vim: ts=2:sw=2:et
