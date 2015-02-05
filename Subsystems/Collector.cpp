#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() : Subsystem("Collector") {
  windowMotorLeft=new CANTalon(COLLECTOR_WINDOW_LEFT_CAN);
  windowMotorRight=new CANTalon(COLLECTOR_WINDOW_RIGHT_CAN);
  collectorMotorLeft=new CANTalon(COLLECTOR_LEFT_CAN);
  collectorMotorRight=new CANTalon(COLLECTOR_RIGHT_CAN);
  boxSwitch=new DigitalInput(COLLECTOR_BOXSWITCH_DIO);
}
void Collector::InitDefaultCommand() {
}
void Collector::MoveArms(float a){
  windowMotorLeft->Set(a);
  windowMotorRight->Set(-a);
}
void Collector::MoveRollers(double a){
  printf("Collector: %f\n", a);
  collectorMotorLeft->Set(a);
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
