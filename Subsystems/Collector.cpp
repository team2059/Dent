#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector(): Subsystem("Collector"){
  collectorMotorLeft=new CANTalon(COLLECTOR_LEFT_CAN);
  collectorMotorBottom=new CANTalon(COLLECTOR_BOTTOM_CAN);
  collectorMotorRamp=new CANTalon(COLLECTOR_RAMP_CAN);
  collectorMotorRight=new CANTalon(COLLECTOR_RIGHT_CAN);
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
