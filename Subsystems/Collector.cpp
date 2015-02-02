#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() : Subsystem("Collector") {
  windowMotorLeft=new CANTalon(50);
  windowMotorRight=new CANTalon(51);
  collectorMotorLeft=new CANTalon(52);
  collectorMotorRight=new CANTalon(53);
  boxSwitch=new DigitalInput(9);
}
void Collector::InitDefaultCommand() {
}
void Collector::MoveArms(float a){
    windowMotorLeft->Set(a);
    windowMotorRight->Set(-a);
    a++;
}
void Collector::MoveRollers(float a){
    collectorMotorLeft->Set(a);
    collectorMotorRight->Set(-a);
    r++;
}
bool Collector::ArmsDoneMoving(){
    //TODO calibrate these values or find a sensor to use
    if(a>=200){
        return true;
    }else{
        return false;
    }
}
bool Collector::BoxCollected(){
    return boxSwitch->Get();
}
