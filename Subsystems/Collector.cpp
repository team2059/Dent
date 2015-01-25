#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() : Subsystem("Collector") {
  motor1=new Talon(0);
  motor2=new Talon(1);
}
void Collector::InitDefaultCommand() {
}
void Collector::Set(float power){
  motor1->Set(power);
  motor2->Set(power);
}
