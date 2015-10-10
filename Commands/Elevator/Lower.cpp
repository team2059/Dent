#include "Lower.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Lower::Lower(double timeout, bool useSoftLimits, double liftSpeed): Command("Lower") {
  SetTimeout(timeout);
  softLimits=useSoftLimits;
  speed=liftSpeed;
}
void Lower::Initialize() {}
void Lower::Execute() {
  if(DentRobot::oi->GetRightStick()->GetRawButton(11)){
    speed*=0.5;
  }
  DentRobot::elevator->Run(speed);
}
bool Lower::IsFinished() {
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void Lower::End() {
  DentRobot::elevator->Run(0.0f);
}
void Lower::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
