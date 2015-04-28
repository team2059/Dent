#include "BinElevator.h"
#include "../RobotMap.h"
BinElevator::BinElevator(){
  motor = new CANTalon(BINELEVATOR_CAN);
  elevatorEncoder = new Encoder(BINELEVATOR_ENCODERA, BINELEVATOR_ENCODERB, false);
  elevatorBottom = new DigitalInput(BINELEVATOR_BOTTOM_DIO);
  elevatorTop = new DigitalInput(BINELEVATOR_TOP_DIO);
}
void BinElevator::InitDefaultCommand(){
}
void BinElevator::Run(double power){
  motor->Set(power);
}
void BinElevator::ResetEncoder(){
  elevatorEncoder->Reset();
}
double BinElevator::GetHeight(){
  return elevatorEncoder->Get();
}
bool BinElevator::GetElevatorBottom(){
  return elevatorBottom->Get();
}
bool BinElevator::GetElevatorTop(){
  return elevatorTop->Get();
}
// vim: ts=2:sw=2:et
