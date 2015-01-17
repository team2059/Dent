#include "DentRobot.h"
DentRobot::DentRobot():
  driveCommand(new Drive()){
  printf("Initialized");
}
void DentRobot::RobotInit(){
  printf("Initializing");
  CommandBase::init();
}
void DentRobot::DisabledPeriodic(){
  Scheduler::GetInstance()->Run();
}
void DentRobot::AutonomousInit(){
}
void DentRobot::AutonomousPeriodic(){
  Scheduler::GetInstance()->Run();
}
void DentRobot::TeleopInit(){
}
void DentRobot::TeleopPeriodic(){
  Scheduler::GetInstance()->Run();
}
void DentRobot::TestPeriodic(){
}
START_ROBOT_CLASS(DentRobot);
