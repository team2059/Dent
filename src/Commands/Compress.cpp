#include "Compress.h"
#include <cmath>
#include "../DentRobot.h"
Compress::Compress() : Command("Compress"){
        Requires(DentRobot::airCompressor);
}
void Compress::Initialize(){
}
void Compress::Execute(){
    DentRobot::airCompressor->CreateCompressedAir();
}
bool Compress::IsFinished(){
  return false;
}
void Compress::End(){
}
void Compress::Interrupted(){
}
