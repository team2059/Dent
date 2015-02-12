#include "DentRobot.h"
#include "Commands/Autonomous/Autonomous.h"
OI* DentRobot::oi=NULL;
Collector* DentRobot::collector=NULL;
Drivetrain* DentRobot::drivetrain=NULL;
Elevator* DentRobot::elevator=NULL;
BinElevator* DentRobot::binElevator=NULL;
CommandGroup* DentRobot::aut=NULL;
DentRobot::DentRobot(){
  oi=new OI();
  collector=new Collector();
  drivetrain=new Drivetrain();
  elevator=new Elevator();
  binElevator=new BinElevator();
  aut=new Autonomous();
  CameraServer::GetInstance()->SetQuality(25);
  CameraServer::GetInstance()->StartAutomaticCapture("cam0");
  printf("Initialized");
}
void DentRobot::RobotInit(){
  SmartDashboard::PutNumber("CodeVersion",0.001);
}
void DentRobot::DisabledPeriodic(){
  Scheduler::GetInstance()->Run();
}
void DentRobot::AutonomousInit(){
  if(aut != NULL){
    aut->Start();
  }
}
void DentRobot::AutonomousPeriodic(){
  Scheduler::GetInstance()->Run();
}
void DentRobot::TeleopInit(){
  //if (aut != NULL){
  //  aut->Cancel();
  //}
}
void DentRobot::TeleopPeriodic(){
  Scheduler::GetInstance()->Run();
}
void DentRobot::TestPeriodic(){
}
START_ROBOT_CLASS(DentRobot);
// vim: ts=2:sw=2:et
