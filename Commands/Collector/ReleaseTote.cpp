#include "ReleaseTote.h"
#include "../../DentRobot.h"
#include "RollOut.h"
#include "../Autonomous/AutoDrive.h"
#include "CloseCollector.h"
ReleaseTote::ReleaseTote(){
  AddParallel(new RollOut());
  AddParallel(new AutoDrive(0.5, 0.75));
  AddSequential(new CloseCollector());
}
// vim: ts=2:sw=2:et
