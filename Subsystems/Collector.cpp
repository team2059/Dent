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
  MoveLeftRoller(power);
  MoveRightRoller(-power);
  MoveBottomRollers(power);
  printf("Roller power: %f\n", power);
}
void Collector::MoveLeftRoller(double power){
  collectorMotorLeft->Set(power);
}
void Collector::MoveRightRoller(double power){
  collectorMotorRight->Set(power);
}
void Collector::MoveBottomRollers(double power){
  collectorMotorBottom->Set(-power);
  collectorMotorRamp->Set(power);
}
double Collector::GetSonarDistance(){
  return sonarAnalog->GetAverageVoltage();
}
// vim: ts=2:sw=2:et
