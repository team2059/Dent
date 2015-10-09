#include "Raise.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Raise::Raise(double timeout, bool useSoftLimits, double liftSpeed): Command("Raise") {
  SetTimeout(timeout);
  softLimits=useSoftLimits;
  speed=liftSpeed;
}
void Raise::Initialize() {}
void Raise::Execute() {
  DentRobot::elevator->Run(speed);
}
bool Raise::IsFinished() {
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void Raise::End() {
  DentRobot::elevator->Run(0.0f);
}
void Raise::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
