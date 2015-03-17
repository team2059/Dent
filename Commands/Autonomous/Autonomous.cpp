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
  Wait(SmartDashboard::GetNumber("Auto Wait Time"));
  switch(seq){
    case 0:
      // Just for testing
      // Turn testing
      AddSequential(new Turn(3.8));
      break;
    case 1:
      // Drive to Auto Zone (TM)
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0.0, -0.8, 0.01));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      break;
    case 2:
      // Lower BinElevator, collect bin, turn, drive to AutoZone (TM)
      AddSequential(new BinLower(0.5));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Bin Distance"), 0.0, 0.75));
      AddSequential(new BinRaise(1.0));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0.0, -0.75));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      break;
    case 3:
      // Collect a tote with BinElevator, turn, drive to Auto Zone (TM)
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      AddSequential(new BinRaise(1.2));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0.0, -0.75));
      AddSequential(new BinLower(1.0));
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      break;
    case 4:
      // Collect one, two, or three totes, drive to Auto Zone (TM), release totes
      AddSequential(new CollectTote(SmartDashboard::GetNumber("CollectToteTurn")));
      if(SmartDashboard::GetBoolean("Two totes")){
        AddParallel(new Turn(0.81));
        AddSequential(new Raise(3.5));
        AddSequential(new AutoDrive(SmartDashboard::GetNumber("Two Tote Distance"), 0.0, 0.75));
        AddSequential(new CollectTote());
        AddSequential(new Lower(3.0));
        AddSequential(new Raise(3.5));
        if(SmartDashboard::GetBoolean("Three totes")){
          AddSequential(new Turn(3.8));
          AddSequential(new AutoDrive(SmartDashboard::GetNumber("Three Tote Distance"), 0.0, 0.75));
          AddSequential(new CollectTote());
          AddSequential(new Lower(3.0));
          AddSequential(new Raise(3.5));
        }
      }
      AddSequential(new Turn(SmartDashboard::GetNumber("TurnAmount")));
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("Auto Zone Distance"), 0.0, 0.75));
      AddSequential(new ReleaseTote());
      break;
    case 5:
      // Same as auto 4, but navigate around bins
      //TODO: Implement this
      break;
    case 6:
      // Collect 1 bin and 1 tote
      //TODO: Implement this
      break;
    case 7:
      // Same as auto 4 with (Three|Two) totes checked, collect bin, drive to Auto Zone (TM), release totes
      //TODO: Implement this
      break;
    default:
      printf("Invalid seq: %d\n", seq);
      break;
  }
}
// vim: ts=2:sw=2:et
