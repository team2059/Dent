#include "BinOut.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinOut::BinOut(double timeout): Command("BinOut") {
  SetTimeout(timeout);
}
void BinOut::Initialize() {
}
void BinOut::Execute() {
  DentRobot::binCollector->MoveArms(-0.1);
}
bool BinOut::IsFinished() {
  if(IsTimedOut()) {
    printf("Robot stopped ejecting bin.\n");
    return true;
  } else {
    return false;
  }
}
void BinOut::End() {
  DentRobot::binCollector->MoveArms(0.0);
}
void BinOut::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
