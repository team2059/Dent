#include "CloseCollector.h"
CloseCollector::CloseCollector() : Command("CloseCollector"){
    Requires(DentRobot::collector);
}
void CloseCollector::Initialize(){
  SetTimeout(0.5);
}
void CloseCollector::Execute(){
    DentRobot::collector->MoveArms(.1);
}
bool CloseCollector::IsFinished(){
    return DentRobot::collector->ArmSensor();
}
void CloseCollector::End(){
}
void CloseCollector::Interrupted(){
  End();
}
