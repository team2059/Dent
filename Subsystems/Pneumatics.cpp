#include "Pneumatics.h"
#include "../RobotMap.h"

Pneumatics::Pneumatics(): Subsystem("Pneumatics") {
  compressor = new Compressor(COMPRESSOR_PCM_CAN);
  solenoid1 = new Solenoid(BINELEVATOR_SOLDENOID_ONE);
  solenoid2 = new Solenoid(BINELEVATOR_SOLDENOID_TWO);
  armState = false;
}
void Pneumatics::InitDefaultCommand() {
}
void Pneumatics::SetArmsOpen(bool state) {
  if(state) {
    solenoid1->Set(true);
    solenoid2->Set(false);
    armState = true;
  } else {
    solenoid1->Set(false);
    solenoid2->Set(true);
    armState = false;
  }
}
void Pneumatics::SetCompressorEnabled(bool state){
  compressor->SetClosedLoopControl(state);
}
bool Pneumatics::GetArmsOpen(){
  return armState;
}
bool Pneumatics::GetCompressorEnabled(){
  return compressor->Enabled();
}
// vim: ts=2:sw=2:et
