#include "ContainerElevator.h"
#include "../RobotMap.h"
ContainerElevator::ContainerElevator(){
  motor=new CANTalon(CONTAINER_ELEVATOR_CAN);
  elevatorEncoder=new Encoder(CONTAINER_ELEVATOR_ENCODERA, CONTAINER_ELEVATOR_ENCODERB, false);
  elevatorBottom=new DigitalInput(CONTAINER_ELEVATOR_BOTTOM_DIO);
  elevatorTop=new DigitalInput(CONTAINER_ELEVATOR_TOP_DIO);
}
void ContainerElevator::InitDefaultCommand(){
}
void ContainerElevator::Run(double power){
  motor->Set(power);
}
void ContainerElevator::ResetEncoder(){
  elevatorEncoder->Reset();
}
double ContainerElevator::GetHeight(){
  return elevatorEncoder->Get();
}
bool ContainerElevator::GetElevatorBottom(){
  SmartDashboard::PutBoolean("Container Elevator Bottom", elevatorBottom->Get());
  return elevatorBottom->Get();
}
bool ContainerElevator::GetElevatorTop(){
  SmartDashboard::PutBoolean("Container Elevator Top", elevatorTop->Get());
  return elevatorTop->Get();
}
// vim: ts=2:sw=2:et
