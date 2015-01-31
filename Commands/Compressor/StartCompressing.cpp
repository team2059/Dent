#include "StartCompressing.h"
#include <cmath>
#include "../../DentRobot.h"
StartCompressing::StartCompressing() : Command("StartCompressing"){
        Requires(DentRobot::airCompressor);
}
void StartCompressing::Initialize(){
}
void StartCompressing::Execute(){
    DentRobot::airCompressor->CreateCompressedAir();
}
bool StartCompressing::IsFinished(){
  return false;
}
void StartCompressing::End(){
}
void StartCompressing::Interrupted(){
}
