#include "Drive.h"
#include "../DentRobot.h"
Drive::Drive() : Command("Drive"){
        Requires(DentRobot::drivetrain);
}
void Drive::Initialize(){
}
void Drive::Execute(){
  DentRobot::drivetrain->DriveMecanum(DentRobot::oi->GetLeftStick()->GetRawAxis(2), DentRobot::oi->GetLeftStick()->GetRawAxis(1), DentRobot::oi->GetLeftStick()->GetRawAxis(0));
}
bool Drive::IsFinished(){
  return false;
}
void Drive::End(){
}
void Drive::Interrupted(){
}
