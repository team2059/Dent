#include "BinElevator.h"
#include "../RobotMap.h"
BinElevator::BinElevator(){
  motor=new CANTalon(BINELEVATOR_CAN);
  elevatorEncoder=new Encoder(0,1,false);
  offset=0;
  height=0;
  elevatorBottom=new DigitalInput(BINELEVATOR_BOTTOM_DIO);
  elevatorTop=new DigitalInput(BINELEVATOR_TOP_DIO);
  //SetAbsoluteTolerance(0.004);
}
void BinElevator::InitDefaultCommand(){
}
void BinElevator::Run(double power){
  motor->Set(power);
}
void BinElevator::SetOffset(double ht){
  offset=ht;
}
void BinElevator::ResetEncoder(){
  elevatorEncoder->Reset();
}
double BinElevator::GetHeight(){
  return elevatorEncoder->Get()+offset;
}
bool BinElevator::GetElevatorBottom(){
  return elevatorBottom->Get();
}
bool BinElevator::GetElevatorTop(){
  return elevatorTop->Get();
}
// vim: ts=2:sw=2:et
