#include "Raise.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Raise::Raise(double timeout, bool useSoftLimits): Command("Raise") {
  SetTimeout(timeout);
  softLimits=useSoftLimits;
}
void Raise::Initialize() {
}
void Raise::Execute() {
  DentRobot::elevator->Run(1.0);
}
bool Raise::IsFinished() {
  if(softLimits) {
    if(!DentRobot::elevator->GetElevatorTop()||!DentRobot::elevator->GetElevatorMiddle()) {
      return true;
    }
  }
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void Raise::End() {
  // If the elevator is at the top
  if(DentRobot::elevator->GetElevatorTop()) {
    DentRobot::elevator->SetUseEncoder(true);
  }
  DentRobot::elevator->Run(0.0f);
}
void Raise::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
