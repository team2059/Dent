#include "ContainerCloseArms.h"
#include "../../DentRobot.h"
#include "../../OI.h"
ContainerCloseArms::ContainerCloseArms(double timeout): Command("ContainerCloseArms"){
  SetTimeout(timeout);
}
void ContainerCloseArms::Initialize(){
}
void ContainerCloseArms::Execute(){
  DentRobot::pneumatics->SetOpen(false);
}
bool ContainerCloseArms::IsFinished(){
  return true;
}
void ContainerCloseArms::End(){
}
void ContainerCloseArms::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et
