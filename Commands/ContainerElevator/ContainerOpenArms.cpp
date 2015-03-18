#include "ContainerOpenArms.h"
#include "../../DentRobot.h"
#include "../../OI.h"
ContainerOpenArms::ContainerOpenArms(double timeout): Command("ContainerOpenArms"){
  SetTimeout(timeout);
}
void ContainerOpenArms::Initialize(){
}
void ContainerOpenArms::Execute(){
  DentRobot::pneumatics->SetOpen(true);
}
bool ContainerOpenArms::IsFinished(){
  return true;
}
void ContainerOpenArms::End(){
}
void ContainerOpenArms::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et
