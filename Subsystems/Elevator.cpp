#include "Elevator.h"
#include "../RobotMap.h"
Elevator::Elevator(){
  motor=new CANTalon(ELEVATOR_CAN);
  elevatorEncoder=new Encoder(0,1,false);
  offset=0;
  height=0;
  elevatorBottom=new DigitalInput(ELEVATOR_BOTTOM_DIO);
  elevatorTop=new DigitalInput(ELEVATOR_TOP_DIO);
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
bool Elevator::GetElevatorBottom(){
  return elevatorBottom->Get();
}
bool Elevator::GetElevatorTop(){
  return elevatorTop->Get();
}
// vim: ts=2:sw=2:et
