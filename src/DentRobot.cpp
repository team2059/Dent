#include "DentRobot.h"
OI* DentRobot::oi=NULL;
Collector* DentRobot::collector=NULL;
Drivetrain* DentRobot::drivetrain=NULL;
Elevator* DentRobot::elevator=NULL;
DentRobot::DentRobot(){
  oi=new OI();
  collector=new Collector();
  drivetrain=new Drivetrain();
  elevator=new Elevator();
  printf("Initialized");
}
void DentRobot::RobotInit(){
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
