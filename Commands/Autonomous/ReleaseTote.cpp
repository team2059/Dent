#include "ReleaseTote.h"
#include "../../DentRobot.h"
#include "AutoDrive.h"
#include "../Collector/RollOut.h"
ReleaseTote::ReleaseTote(){
  AddParallel(new RollOut());
  AddParallel(new AutoDrive(0.5, 0, 0.75));
}
// vim: ts=2:sw=2:et
