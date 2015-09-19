#include "Pneumatics.h"
#include "../RobotMap.h"

Pneumatics::Pneumatics(): Subsystem("Pneumatics") {
  compressor = new Compressor(COMPRESSOR_PCM_CAN);
  solenoid1 = new Solenoid(COMPRESSOR_PCM_CAN, BINELEVATOR_SOLENOID_ONE);
  solenoid2 = new Solenoid(COMPRESSOR_PCM_CAN, BINELEVATOR_SOLENOID_TWO);
  solenoid3 = new Solenoid(COMPRESSOR_PCM_CAN, BINELEVATOR_SOLENOID_THREE);
  solenoid4 = new Solenoid(COMPRESSOR_PCM_CAN, BINELEVATOR_SOLENOID_FOUR);
  armState = false;
}
void Pneumatics::InitDefaultCommand() {}
void Pneumatics::SetArmsOpen(bool state) {
  if(state) {
    solenoid1->Set(true);
    solenoid2->Set(false);
    solenoid3->Set(true);
    solenoid4->Set(false);
    armState = true;
  } else {
    solenoid1->Set(false);
    solenoid2->Set(true);
    solenoid3->Set(false);
    solenoid4->Set(true);
    armState = false;
  }
}
void Pneumatics::SetCompressorEnabled(bool state) {
  compressor->SetClosedLoopControl(state);
}
bool Pneumatics::GetArmsOpen() {
  return armState;
}
bool Pneumatics::GetCompressorEnabled() {
  return compressor->Enabled();
}
// vim: ts=2:sw=2:et
