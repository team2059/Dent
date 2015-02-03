#include "StartCompressing.h"
#include "../../DentRobot.h"
StartCompressing::StartCompressing() : Command("StartCompressing"){
  Requires(DentRobot::airCompressor);
}
void StartCompressing::Initialize(){
}
void StartCompressing::Execute(){
  DentRobot::airCompressor->StartCompressing();
}
bool StartCompressing::IsFinished(){
  return false;
}
void StartCompressing::End(){
}
void StartCompressing::Interrupted(){
}
