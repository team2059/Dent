#include "CommandBase.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Collector.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/DIO.h"
#include "Subsystems/AirCompressor.h"
Drivetrain* CommandBase::drivetrain = NULL;
Collector* CommandBase::collector = NULL;
Elevator* CommandBase::elevator = NULL;
DIO* CommandBase::dio = NULL;
AirCompressor* CommandBase::airCompressor = NULL;
OI* CommandBase::oi = NULL;
CommandBase::CommandBase(char const *name) : Command(name) {
}
CommandBase::CommandBase() : Command() {
}
void CommandBase::init(){
  drivetrain = new Drivetrain();
  collector = new Collector();
  elevator = new Elevator();
  dio = new DIO();
  airCompressor = new AirCompressor();
  oi = new OI();
}
