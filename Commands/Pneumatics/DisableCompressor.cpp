#include "DisableCompressor.h"
#include "../../DentRobot.h"
#include "../../OI.h"
DisableCompressor::DisableCompressor(double timeout): Command("DisableCompressor") {
  SetTimeout(timeout);
}
void DisableCompressor::Initialize() {}
void DisableCompressor::Execute() {
  DentRobot::pneumatics->SetCompressorEnabled(false);
}
bool DisableCompressor::IsFinished() {
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void DisableCompressor::End() {
}
void DisableCompressor::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
