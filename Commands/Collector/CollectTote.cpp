#include "CollectTote.h"
#include "../../DentRobot.h"
#include "../Autonomous/AutoDrive.h"
#include "RollIn.h"
#include "CloseCollector.h"
CollectTote::CollectTote(){
  AddParallel(new CloseCollector());
  AddSequential(new RollIn());
  // TODO: Fix null error
  //AddParallel(new AutoDrive(0.5, -0.75));
}
// vim: ts=2:sw=2:et
