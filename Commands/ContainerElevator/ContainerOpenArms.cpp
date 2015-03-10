#include "CONTAINER_OpenArms.h"
#include "../../DentRobot.h"
#include "../../OI.h"
CONTAINER_OpenArms::CONTAINER_OpenArms(double timeout): Command("CONTAINER_OpenArms"){
  SetTimeout(timeout);
}
void CONTAINER_OpenArms::Initialize(){
}
void CONTAINER_OpenArms::Execute(){
  DentRobot::pneumatics->SetOpen(true);
}
bool CONTAINER_OpenArms::IsFinished(){
  return true;
}
void CONTAINER_OpenArms::End(){
}
void CONTAINER_OpenArms::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et
