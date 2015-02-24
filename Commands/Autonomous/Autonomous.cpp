#include "Autonomous.h"
#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
#include "../Elevator/Raise.h"
#include "../Elevator/Lower.h"
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
      AddSequential(new CollectTote());
      AddSequential(new Turn(90));
      break;
    case 1:
      // Wait a desigated value, drive to Auto Zone (TM)
      Wait(SmartDashboard::GetNumber("Auto Wait Time"));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), -0.75));
      break;
    case 2:
      // Get one tote and go to Auto Zone (TM)
      AddSequential(new CollectTote());
      AddSequential(new Turn(90));
      AddSequential(new ReleaseTote());
      break;
    case 3:
      // Collect three totes, drive to Auto Zone (TM)
      printf("Waiting: %f\n",SmartDashboard::GetNumber("Auto Wait Time"));
      Wait(SmartDashboard::GetNumber("Auto Wait Time"));
      printf("Done");
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Tote Distance"), -0.75));
      AddSequential(new CollectTote());
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Tote Distance"), -0.75));
      AddSequential(new CollectTote());
      printf("Three totes?: %d\n",SmartDashboard::GetBoolean("Three totes"));
      if(SmartDashboard::GetBoolean("Three totes")){
        AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Tote Distance"), -0.75));
        AddSequential(new CollectTote());
      }
      AddSequential(new Turn(90));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), -0.75));
      AddSequential(new ReleaseTote());
      break;
    default:
      printf("Invalid seq: %d\n", seq);
      break;
  }
}
// vim: ts=2:sw=2:et
