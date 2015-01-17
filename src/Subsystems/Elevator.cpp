#include "Elevator.h"
#include "../RobotMap.h"
//Elevator::Elevator() : PIDSubsystem("Elevator", kP_real, kI_real, 0.0){
Elevator::Elevator() : Subsystem("Elevator"){
  pot=new AnalogPotentiometer(0);
  leftMotor=new Talon(1);
  rightMotor=new Talon(0);
  //SetAbsoluteTolerance(0.004);
}
void Elevator::InitDefaultCommand(){
}
float Elevator::GetPotValue(){
  return pot->Get();
}
void Elevator::Run(double power){
  leftMotor->Set(power);
  rightMotor->Set(power);
}
