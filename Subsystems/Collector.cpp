#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() : Subsystem("Collector"){
  collectorMotorLeft=new CANTalon(COLLECTOR_LEFT_CAN);
  collectorMotorBottom=new CANTalon(COLLECTOR_BOTTOM_CAN);
  collectorMotorRamp=new CANTalon(COLLECTOR_RAMP_CAN);
  collectorMotorRight=new CANTalon(COLLECTOR_RIGHT_CAN);
  sonarAnalog=new AnalogInput(COLLECTOR_SONAR_ANALOG);
}
void Collector::InitDefaultCommand(){
}
void Collector::MoveRollers(double a){
  collectorMotorLeft->Set(a);
  collectorMotorBottom->Set(-a);
  collectorMotorRamp->Set(a);
  collectorMotorRight->Set(-a);
  printf("Roller power: %f\n",a);
}
double Collector::GetSonarDistance(){
  return sonarAnalog->GetAverageVoltage();
}
// vim: ts=2:sw=2:et
