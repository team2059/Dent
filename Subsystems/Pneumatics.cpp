#include "Pneumatics.h"
#include "../RobotMap.h"

Pneumatics::Pneumatics(): Subsystem("Pneumatics") {
  solenoid1 = new Solenoid(BINELEVATOR_SOLDENOID_ONE);
  solenoid2 = new Solenoid(BINELEVATOR_SOLDENOID_TWO);
}
void Pneumatics::InitDefaultCommand() {
}
void Pneumatics::SetOpen(bool state) {
  if(state) {
    solenoid1->Set(true);
    solenoid2->Set(false);
  } else {
    solenoid1->Set(false);
    solenoid2->Set(true);
  }
}
// vim: ts=2:sw=2:et
