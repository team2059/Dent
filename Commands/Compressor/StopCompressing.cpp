#include "StopCompressing.h"
#include "../../DentRobot.h"
StopCompressing::StopCompressing() : Command("StopCompressing"){
  Requires(DentRobot::airCompressor);
}
void StopCompressing::Initialize(){
}
void StopCompressing::Execute(){
  DentRobot::airCompressor->StopCompressing();
}
bool StopCompressing::IsFinished(){
  return false;
}
void StopCompressing::End(){
}
void StopCompressing::Interrupted(){
  End();
}
