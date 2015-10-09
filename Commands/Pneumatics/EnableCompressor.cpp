#include "EnableCompressor.h"
#include "../../DentRobot.h"
#include "../../OI.h"
EnableCompressor::EnableCompressor(double timeout): Command("EnableCompressor") {
  SetTimeout(timeout);
}
void EnableCompressor::Initialize() {}
void EnableCompressor::Execute() {
  DentRobot::pneumatics->SetCompressorEnabled(true);
}
bool EnableCompressor::IsFinished() {
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void EnableCompressor::End() {
}
void EnableCompressor::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
