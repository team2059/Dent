#include "HHBase.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
HHBase::HHBase():
  hhbot(new HHRobot()){
    printf("Done\n");
  }
void HHBase::RobotInit(){
  hhbot->Init();
}
void HHBase::DisabledInit(){}
void HHBase::AutonomousInit(){
  hhbot->Init();
}
void HHBase::TeleopInit(){
  hhbot->Init();
}
void HHBase::DisabledContinuous(){}
void HHBase::AutonomousContinuous(){}
void HHBase::TeleopContinuous(){}
void HHBase::DisabledPeriodic(){}
void HHBase::AutonomousPeriodic(){
}
void HHBase::TeleopPeriodic(){
  hhbot->Handler();
}
void HHBase::Test(){}
START_ROBOT_CLASS(HHBase);
// vim: ts=2:sw=2:et
