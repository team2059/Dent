#include "CommandBase.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Collector.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/BinElevator.h"
Drivetrain* CommandBase::drivetrain = NULL;
Collector* CommandBase::collector = NULL;
Elevator* CommandBase::elevator = NULL;
BinElevator* CommandBase::binElevator = NULL;
OI* CommandBase::oi = NULL;
CommandBase::CommandBase(char const *name) : Command(name) {
}
CommandBase::CommandBase() : Command() {
}
void CommandBase::init(){
  drivetrain = new Drivetrain();
  collector = new Collector();
  elevator = new Elevator();
  binElevator = new BinElevator();
  oi = new OI();
}
// vim: ts=2:sw=2:et
