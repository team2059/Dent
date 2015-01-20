#include "CommandBase.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Collector.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/AirCompressor.h"
#include "Commands/Drive.h"
#include "Commands/Collect.h"
#include "Commands/Eject.h"
#include "Commands/Raise.h"
#include "Commands/Lower.h"
Drivetrain* CommandBase::drivetrain = NULL;
Collector* CommandBase::collector = NULL;
Elevator* CommandBase::elevator = NULL;
AirCompressor* CommandBase::airCompressor = NULL;
OI* CommandBase::oi = NULL;
CommandBase::CommandBase(char const *name) : Command(name) {
}
CommandBase::CommandBase() : Command() {
}
void CommandBase::init()
{
  drivetrain = new Drivetrain();
  collector = new Collector();
  elevator = new Elevator();
  airCompressor = new AirCompressor();
  oi = new OI();
}
