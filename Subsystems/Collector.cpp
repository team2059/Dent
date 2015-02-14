#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() : Subsystem("Collector") {
  collectorMotorLeft=new CANTalon(COLLECTOR_LEFT_CAN);
  collectorMotorBottom=new CANTalon(COLLECTOR_BOTTOM_CAN);
  collectorMotorRight=new CANTalon(COLLECTOR_RIGHT_CAN);
}
void Collector::InitDefaultCommand() {
}
void Collector::MoveRollers(double a){
  collectorMotorLeft->Set(a);
  collectorMotorBottom->Set(a);
  collectorMotorRight->Set(-a);
}
bool Collector::ArmSensor(){
  // TODO: include limit switch code
  return false;
}
bool Collector::BoxCollected(){
  return false;
  //return boxSwitch->Get();
}
// vim: ts=2:sw=2:et
