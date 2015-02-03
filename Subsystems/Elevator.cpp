#include "Elevator.h"
#include "../RobotMap.h"
Elevator::Elevator()/* : PIDSubsystem("Elevator", kP_real, kI_real, 0.0)*/{
  motor=new CANTalon(ELEVATOR_CAN);
  elevatorEncoder=new Encoder(0,1,false);
  offset=0;
  height=0;
  //SetAbsoluteTolerance(0.004);
}
void Elevator::InitDefaultCommand(){
}
void Elevator::Run(double power){
  motor->Set(power);
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
