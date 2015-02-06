#include "Autonomous.h"
#include "AutoDrive.h"
#include <cmath>
#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
Autonomous::Autonomous() : CommandGroup("Autonomous"){
  AddSequential(new AutoDrive());
}
void Autonomous::Initialize(){
}
void Autonomous::Execute(){
}
bool Autonomous::IsFinished(){
  return false;
}
void Autonomous::End(){
}
void Autonomous::Interrupted(){
  End();
}
