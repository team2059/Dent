#include "Autonomous.h"
#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
#include "../Elevator/Raise.h"
#include "../Elevator/Lower.h"
#include "../BinElevator/BinRaise.h"
#include "../BinElevator/BinLower.h"
#include "AutoDrive.h"
#include "Turn.h"
#include "../Collector/RollIn.h"
#include "CollectTote.h"
#include "ReleaseTote.h"
Autonomous::Autonomous(int seq){
  //SmartDashboard::GetNumber("Auto Wait Time");
  switch(seq){
    case 0:
      // Just for testing
      // Strafe at .25 power
      AddSequential(new AutoDrive(0.5, 0.25, 0.0));
      break;
    case 1:
      // Drive to Auto Zone (TM)
      Wait(SmartDashboard::GetNumber("Auto Wait Time"));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0.0, -0.8));
      break;
    case 2:
      // Collect a tote, turn, drive to Auto Zone (TM)
      Wait(SmartDashboard::GetNumber("Auto Wait Time"));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      AddSequential(new BinRaise(1.2));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0.0, -0.75));
      AddSequential(new BinLower(1.0));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      break;
    case 3:
      // Collect three totes, drive to Auto Zone (TM)
      printf("Waiting: %f\n", SmartDashboard::GetNumber("Auto Wait Time"));
      Wait(SmartDashboard::GetNumber("Auto Wait Time"));
      printf("Done");
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Tote Distance"), 0, 0.75));
      AddSequential(new CollectTote());
      AddSequential(new Raise());
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Tote Distance"), 0, 0.75));
      AddSequential(new CollectTote());
      AddSequential(new Lower());
      AddSequential(new Raise());
      printf("Three totes?: %d\n", SmartDashboard::GetBoolean("Three totes"));
      if(SmartDashboard::GetBoolean("Three totes")){
        AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Tote Distance"), 0, 0.75));
        AddSequential(new CollectTote());
        AddSequential(new Lower());
        AddSequential(new Raise());
      }
      AddSequential(new Turn(90));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0, 0.75));
      AddSequential(new ReleaseTote());
      break;
    default:
      printf("Invalid seq: %d\n", seq);
      break;
  }
}
// vim: ts=2:sw=2:et
