#include "CollectTote.h"
#include "../../DentRobot.h"
#include "AutoDrive.h"
#include "../Collector/RollIn.h"
CollectTote::CollectTote(double z) {
  AddParallel(new AutoDrive(SmartDashboard::GetNumber("DriveTime1"), 0.0, 0.75, z, false));
  AddSequential(new RollIn(1.0));
}
// vim: ts=2:sw=2:et
