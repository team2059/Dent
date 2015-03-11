#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector(): Subsystem("Collector"){
  collectorMotorLeft=new Victor(COLLECTOR_LEFT);
  collectorMotorBottom=new Victor(COLLECTOR_BOTTOM);
  collectorMotorRamp=new Victor(COLLECTOR_RAMP);
  collectorMotorRight=new Victor(COLLECTOR_RIGHT);
  sonarAnalog=new AnalogInput(COLLECTOR_SONAR_ANALOG);
}
void Collector::InitDefaultCommand(){
}
void Collector::MoveRollers(double power){
  collectorMotorLeft->Set(power);
  collectorMotorBottom->Set(-power);
  collectorMotorRamp->Set(power);
  collectorMotorRight->Set(-power);
  printf("Roller power: %f\n", power);
}
double Collector::GetSonarDistance(){
  return sonarAnalog->GetAverageVoltage();
}
// vim: ts=2:sw=2:et
