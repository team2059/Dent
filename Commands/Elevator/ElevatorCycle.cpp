#include "Commands/CommandGroup.h"
#include "ElevatorCycle.h"
#include "../../DentRobot.h"
#include "../Elevator/Raise.h"
#include "../Elevator/Lower.h"
ElevatorCycle::ElevatorCycle() {
  AddSequential(new Raise(3.5));
  AddSequential(new Lower(3.0));
}
