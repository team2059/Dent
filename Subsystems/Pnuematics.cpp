#include "Pnuematics.h"
#include "../RobotMap.h"

Pnuematics::Pnuematics() : Subsystem("Pnuematics"){
  solenoid1 = new Solenoid(BINELEVATOR_SOLDENOID_ONE);
  solenoid2 = new Solenoid(BINELEVATOR_SOLDENOID_TWO);
}
void Pnuematics::InitDefaultCommand(){
}
void Pnuematics::SetOpen(bool k){
  if(k){
    solenoid1->Set(true);
    solenoid2->Set(false);
  }else{
    solenoid1->Set(false);
    solenoid2->Set(true);
  }
}
// vim: ts=2:sw=2:et
