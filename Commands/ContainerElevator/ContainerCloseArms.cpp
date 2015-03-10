#include "CONTAINER_CloseArms.h"
#include "../../DentRobot.h"
#include "../../OI.h"
CONTAINER_CloseArms::CONTAINER_CloseArms(double timeout): Command("CONTAINER_CloseArms"){
  SetTimeout(timeout);
}
void CONTAINER_CloseArms::Initialize(){
}
void CONTAINER_CloseArms::Execute(){
  DentRobot::pneumatics->SetOpen(false);
}
bool CONTAINER_CloseArms::IsFinished(){
  return true;
}
void CONTAINER_CloseArms::End(){
}
void CONTAINER_CloseArms::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et
