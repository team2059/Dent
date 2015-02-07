#include "CommandBase.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Collector.h"
#include "Subsystems/Elevator.h"
Drivetrain* CommandBase::drivetrain = NULL;
Collector* CommandBase::collector = NULL;
Elevator* CommandBase::elevator = NULL;
OI* CommandBase::oi = NULL;
CommandBase::CommandBase(char const *name) : Command(name) {
}
CommandBase::CommandBase() : Command() {
}
void CommandBase::init(){
  drivetrain = new Drivetrain();
  collector = new Collector();
  elevator = new Elevator();
  oi = new OI();
}
// vim: ts2:sw=2:et
