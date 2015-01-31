#include "Elevator.h"
#include "../RobotMap.h"
Elevator::Elevator()/* : PIDSubsystem("Elevator", kP_real, kI_real, 0.0)*/{
  pot=new AnalogPotentiometer(0);
  leftMotor=new Talon(1);
  rightMotor=new Talon(0);
  height=0;
  //SetAbsoluteTolerance(0.004);
}
void Elevator::InitDefaultCommand(){
}
float Elevator::GetPotValue(){
  return pot->Get();
}
void Elevator::Run(double power){
  // Height supposed to be the location of the elevator
  //height+=power;
  leftMotor->Set(power);
  rightMotor->Set(power);
}
void Elevator::SetHeight(double ht){
  height=ht;
}
double Elevator::GetHeight(){
  return height;
}
