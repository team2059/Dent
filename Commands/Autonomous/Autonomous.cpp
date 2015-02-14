#include "Autonomous.h"
#include "../../DentRobot.h"
#include "../Elevator/Raise.h"
#include "../Elevator/Lower.h"
#include "AutoDrive.h"
#include "Turn.h"
#include "../Collector/CloseCollector.h"
#include "../Collector/OpenCollector.h"
#include "../Collector/RollIn.h"
Autonomous::Autonomous(int seq){
  SmartDashboard::GetNumber("Auto Wait Time");
  switch(seq){
    case 0:
      // Just for testing
      AddSequential(new Raise());
      AddSequential(new Lower());
      AddSequential(new OpenCollector());
      AddSequential(new CloseCollector());
      AddSequential(new Turn());
      AddParallel(new AutoDrive(0.5));
      AddParallel(new CloseCollector());
      AddSequential(new RollIn());
      AddSequential(new Turn());
      break;
    case 1:
      // Drive forward a bit, turn around, collect tote then bin
      AddParallel(new Raise());
      AddSequential(new AutoDrive(0.5));
      AddSequential(new Turn());
      AddSequential(new Turn());
      AddSequential(new RollIn());
      break;
    case 2:
      // Drive forward a bit, turn around, collect tote then bin
      AddParallel(new Raise());
      AddParallel(new AutoDrive(0.5));
      AddSequential(new Turn());
      AddSequential(new Turn());
      AddSequential(new RollIn());
      break;
    case 3:
      // Wait a desigated value, drive to Auto Zone (TM)
      Wait(SmartDashboard::GetNumber("Auto Wait Time"));
      AddSequential(new AutoDrive(2.0));
      break;
    default:
      printf("Invalid seq: %d\n", seq);
      break;
  }
}
// vim: ts=2:sw=2:et
