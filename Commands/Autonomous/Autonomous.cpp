#include "Autonomous.h"
#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
#include "../Elevator/Raise.h"
#include "../Elevator/Lower.h"
#include "../ContainerElevator/ContainerRaise.h"
#include "../ContainerElevator/ContainerLower.h"
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
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      break;
    case 2:
      // Lower ContainerElevator, collect container, turn, drive to AutoZone (TM)
      AddSequential(new ContainerLower(0.5));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Container Distance"), 0, 0.75));
      AddSequential(new ContainerRaise(1.0));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0.0, -0.75));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      break;
    case 3:
      // Collect a tote with ContainerElevator, turn, drive to Auto Zone (TM)
      Wait(SmartDashboard::GetNumber("Auto Wait Time"));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      AddSequential(new ContainerRaise(1.2));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0.0, -0.75));
      AddSequential(new ContainerLower(1.0));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      break;
    case 4:
      // Collect one, two, or three totes, drive to Auto Zone (TM), release totes
      printf("Waiting: %f\n", SmartDashboard::GetNumber("Auto Wait Time"));
      Wait(SmartDashboard::GetNumber("Auto Wait Time"));
      printf("Done");
      AddSequential(new CollectTote());
      if(SmartDashboard::GetBoolean("Two totes")){
        AddSequential(new Raise(3.5));
        AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Tote Distance"), 0, 0.75));
        AddSequential(new CollectTote());
        AddSequential(new Lower(3.0));
        AddSequential(new Raise(3.5));
        if(SmartDashboard::GetBoolean("Three totes")){
          AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Tote Distance"), 0, 0.75));
          AddSequential(new CollectTote());
          AddSequential(new Lower(3.0));
          AddSequential(new Raise(3.5));
        }
      }
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0, 0.75));
      AddSequential(new ReleaseTote());
      break;
    case 5:
      // Same as auto 4, but navigate around containers
      //TODO: Implement this
      break;
    case 6:
      // Collect 1 container and 1 tote
      //TODO: Implement this
      break;
    case 7:
      // Same as auto 4 with (Three|Two) totes checked, collect container, drive to Auto Zone (TM), release totes
      //TODO: Implement this
      break;
    default:
      printf("Invalid seq: %d\n", seq);
      break;
  }
}
// vim: ts=2:sw=2:et
