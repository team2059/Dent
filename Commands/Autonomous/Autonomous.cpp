#include "Autonomous.h"
#include "../../DentRobot.h"
#include "../Elevator/Raise.h"
#include "../Elevator/Lower.h"
#include "AutoDrive.h"
#include "Turn.h"
#include "../Collector/CloseCollector.h"
#include "../Collector/OpenCollector.h"
#include "../Collector/CollectTote.h"
Autonomous::Autonomous(){
  //AddSequential(new Raise());
  //AddSequential(new Lower());
  //AddSequential(new AutoDrive());
  AddSequential(new Raise());
  AddSequential(new Lower());
  AddSequential(new Turn());
  AddParallel(new AutoDrive());
  AddParallel(new CloseCollector());
  AddParallel(new CollectTote());
  AddSequential(new Turn());
}
// vim: ts=2:sw=2:et
