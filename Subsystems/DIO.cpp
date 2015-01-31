#include "DIO.h"
#include "../RobotMap.h"
DIO::DIO(){
  elevatorTop=new DigitalInput(0);
  elevatorBottom=new DigitalInput(1);
}
void DIO::InitDefaultCommand(){
}
bool DIO::Get(e_dioSig dioSig){
  if(dioSig == ELEVATORTOP){
    // The top elevator digitalinput was triggered
    return elevatorTop->Get();
  }else if(dioSig == ELEVATORBOTTOM){
    // The buttom elevator digitalinput was triggered
    return elevatorBottom->Get();
  }
  return false;
}
