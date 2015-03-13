#include "CollectTote.h"
#include "../../DentRobot.h"
#include "AutoDrive.h"
#include "../Collector/RollIn.h"
CollectTote::CollectTote(){
  AddParallel(new AutoDrive(1.0, 0.0, 0.75));
  AddSequential(new RollIn(1.0));
}
// vim: ts=2:sw=2:et
