#include "Elevator.h"
#include "../RobotMap.h"
Elevator::Elevator(){
  motor=new CANTalon(ELEVATOR_CAN);
  elevatorEncoder=new Encoder(ELEVATOR_ENCODERA,ELEVATOR_ENCODERB,false);
  elevatorBottom=new DigitalInput(ELEVATOR_BOTTOM_DIO);
  elevatorTop=new DigitalInput(ELEVATOR_TOP_DIO);
}
void Elevator::InitDefaultCommand(){
}
void Elevator::Run(double power){
  motor->Set(power);
}
void Elevator::ResetEncoder(){
  elevatorEncoder->Reset();
}
double Elevator::GetHeight(){
  return elevatorEncoder->Get();
}
bool Elevator::GetElevatorBottom(){
  return elevatorBottom->Get();
}
bool Elevator::GetElevatorTop(){
  return elevatorTop->Get();
}
// vim: ts=2:sw=2:et
