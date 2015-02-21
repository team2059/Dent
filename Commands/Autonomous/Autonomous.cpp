#include "Autonomous.h"
#include "../../DentRobot.h"
#include "../Elevator/Raise.h"
#include "../Elevator/Lower.h"
#include "AutoDrive.h"
#include "Turn.h"
#include "../Collector/RollIn.h"
#include "../Collector/CollectTote.h"
Autonomous::Autonomous(int seq){
  //SmartDashboard::GetNumber("Auto Wait Time");
  switch(seq){
    case 0:
      // Just for testing
      AddSequential(new CollectTote());
      AddSequential(new Turn(90));
      //AddSequential(new Raise());
      //AddSequential(new Lower());
      //AddSequential(new Turn());
      //AddParallel(new AutoDrive(0.5));
      //AddSequential(new RollIn());
      //AddSequential(new Turn());
      break;
    case 1:
      // Drive forward a bit, turn around, collect tote then bin
      AddSequential(new AutoDrive(1.0,-0.75));
      AddSequential(new Turn(180));
      AddSequential(new RollIn(1.0));
      AddSequential(new Raise());
      break;
    case 2:
      // Drive forward a bit, turn around, collect tote then bin
      AddParallel(new Raise());
      AddSequential(new AutoDrive(1.0,-0.75));
      AddSequential(new Turn(180));
      AddSequential(new RollIn(1.0));
      break;
    case 3:
      //Wait(SmartDashboard::GetNumber("Auto Wait Time"));
      AddSequential(new AutoDrive(1.0,-0.75));
      break;
    default:
      printf("Invalid seq: %d\n", seq);
      break;
  }
}
// vim: ts=2:sw=2:et
