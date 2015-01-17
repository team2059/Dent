#include "Drive.h"
#include <cmath>
#include "../DentRobot.h"
Drive::Drive() : Command("Drive"){
}
void Drive::Initialize(){
}
void Drive::Execute(){
  static float sens=0.7;
  float x, y, twist;
  x=DentRobot::oi->GetLeftStick()->GetRawAxis(0);
  y=DentRobot::oi->GetLeftStick()->GetRawAxis(1);
  twist=DentRobot::oi->GetLeftStick()->GetRawAxis(2);
  if(true){
    x=sens*std::pow(x, 3)+(1.0f-sens)*x;
    y=sens*std::pow(y, 3)+(1.0f-sens)*y;
  }
  //DentRobot::drivetrain->DriveMecanum(DentRobot::oi->GetLeftStick()->GetRawAxis(2), DentRobot::oi->GetLeftStick()->GetRawAxis(1), DentRobot::oi->GetLeftStick()->GetRawAxis(0));
  DentRobot::drivetrain->DriveMecanum(x, y, twist);
}
bool Drive::IsFinished(){
  return false;
}
void Drive::End(){
}
void Drive::Interrupted(){
}
