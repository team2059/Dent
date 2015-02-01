#include "Elevator.h"
#include "../RobotMap.h"
Elevator::Elevator()/* : PIDSubsystem("Elevator", kP_real, kI_real, 0.0)*/{
  pot=new AnalogPotentiometer(0);
  leftMotor=new CANTalon(1);
  rightMotor=new CANTalon(0);
  elevatorEncoder=new Encoder(0,1,false);
  offset=0;
  height=0;
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
void Elevator::SetOffset(double ht){
  offset=ht;
}
void Elevator::ResetEncoder(){
  elevatorEncoder->Reset();
}
double Elevator::GetHeight(){
  return elevatorEncoder->Get()+offset;
}
