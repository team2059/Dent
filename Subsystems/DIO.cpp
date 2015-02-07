#include "DIO.h"
#include "../RobotMap.h"
DIO::DIO(){
  elevatorTop=new DigitalInput(0);
  elevatorBottom=new DigitalInput(1);
}
void DIO::InitDefaultCommand(){
}
bool DIO::Get(e_dioSig dioSig){
  switch (dioSig){
    case ELEVATORTOP:
        printf("Hit top limit switch\n");
        return elevatorTop->Get();
        break;
    case ELEVATORBOTTOM:
        printf("Hit top bottom switch\n");
        return elevatorBottom->Get();
        break;
    default:
        return false;
        break;
  }
}
