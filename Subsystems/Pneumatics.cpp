#include "Pneumatics.h"
#include "../RobotMap.h"

Pneumatics::Pneumatics(): Subsystem("Pneumatics") {
  compressor = new Compressor(COMPRESSOR_PCM_CAN);
  solenoid1 = new Solenoid(COMPRESSOR_PCM_CAN, BINELEVATOR_SOLENOID_ONE);
  solenoid2 = new Solenoid(COMPRESSOR_PCM_CAN, BINELEVATOR_SOLENOID_TWO);
  solenoid3 = new Solenoid(COMPRESSOR_PCM_CAN, BINELEVATOR_SOLENOID_THREE);
  solenoid4 = new Solenoid(COMPRESSOR_PCM_CAN, BINELEVATOR_SOLENOID_FOUR);
  armState = false;
  clawState = true;
}
void Pneumatics::InitDefaultCommand() {}
void Pneumatics::SetArmsOpen(bool state) {
  solenoid1->Set(state);
  solenoid2->Set(!state);
  armState=state;
}
void Pneumatics::SetClawOpen(bool state) {
  solenoid3->Set(state);
  solenoid4->Set(!state);
  clawState=state;
}
void Pneumatics::SetCompressorEnabled(bool state) {
  compressor->SetClosedLoopControl(state);
}
bool Pneumatics::GetArmsOpen() {
  return armState;
}
bool Pneumatics::GetClawOpen() {
  return clawState;
}
bool Pneumatics::GetCompressorEnabled() {
  return compressor->Enabled();
}
// vim: ts=2:sw=2:et
