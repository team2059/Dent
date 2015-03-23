#include "Elevator.h"
#include "../RobotMap.h"
Elevator::Elevator(){
  motor = new CANTalon(ELEVATOR_CAN);
  elevatorEncoder = new Encoder(ELEVATOR_ENCODERA, ELEVATOR_ENCODERB, false);
  elevatorBottom = new DigitalInput(ELEVATOR_BOTTOM_DIO);
  elevatorMiddle = new DigitalInput(ELEVATOR_MIDDLE_DIO);
  elevatorTop = new DigitalInput(ELEVATOR_TOP_DIO);
  // Checks if the elevator is drifting
  useEncoder = false;
}
void Elevator::InitDefaultCommand(){
}
void Elevator::Run(double power){
  // If we're not telling it to stop
  if(power != 0.0){
    SetUseEncoder(false);
  }
  motor->Set(power);
}
void Elevator::ResetEncoder(){
  elevatorEncoder->Reset();
}
double Elevator::GetHeight(){
  return elevatorEncoder->Get();
}
bool Elevator::GetElevatorBottom(){
  SmartDashboard::PutBoolean("Elevator Bottom", !elevatorBottom->Get());
  return elevatorBottom->Get();
}
bool Elevator::GetElevatorMiddle(){
  return elevatorMiddle->Get();
}
bool Elevator::GetElevatorTop(){
  SmartDashboard::PutBoolean("Elevator Top", !elevatorTop->Get());
  return elevatorTop->Get();
}
void Elevator::SetUseEncoder(bool use){
  useEncoder = use;
}
bool Elevator::GetUseEncoder(){
  return useEncoder;
}
// vim: ts=2:sw=2:et
