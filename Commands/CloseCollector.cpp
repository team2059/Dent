#include "CloseCollector.h"
CloseCollector::CloseCollector() : Command("CloseCollector"){
    Requires(DentRobot::collector);
}
void CloseCollector::Initialize(){
}
void CloseCollector::Execute(){
    DentRobot::collector->MoveArms(.1);
}
bool CloseCollector::IsFinished(){
    return DentRobot::collector->ArmsDoneMoving();
}
void CloseCollector::End(){
}
void CloseCollector::Interrupted(){
}
