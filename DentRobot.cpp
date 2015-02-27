#include "DentRobot.h"
#include "OI.h"
#include "RobotMap.h"
#include "Commands/Autonomous/Autonomous.h"
OI* DentRobot::oi=NULL;
Collector* DentRobot::collector=NULL;
Drivetrain* DentRobot::drivetrain=NULL;
Elevator* DentRobot::elevator=NULL;
BinElevator* DentRobot::binElevator=NULL;
CommandGroup* DentRobot::aut=NULL;
Pneumatics* DentRobot::pneumatics=NULL;
DentRobot::DentRobot(){
  oi=new OI();
  collector=new Collector();
  drivetrain=new Drivetrain();
  elevator=new Elevator();
  binElevator=new BinElevator();
  pneumatics=new Pneumatics();
  //CameraServer::GetInstance()->SetQuality(25);
  //CameraServer::GetInstance()->StartAutomaticCapture("cam0");
  printf("The robot is on\n");
}
void DentRobot::RobotInit(){
  SmartDashboard::PutNumber("CodeVersion", CODE_VERSION);
  // Autonomous
  // Sequence of autonomous command
  SmartDashboard::PutNumber("Auto Sequence", 2.0);
  SmartDashboard::PutNumber("Auto Wait Time", 3.0);
  // If the robot will be picking up three totes in sequence 3
  SmartDashboard::PutBoolean("Three totes", true);
  // TODO: Calibrate the following two values
  // Distance (in time) to auto zone
  SmartDashboard::PutNumber("Auto Zone Distance", 2.8);
  // Distance (in time) to auto tote (used in sequence 3)
  SmartDashboard::PutNumber("Auto Tote Distance", 0.5);
  SmartDashboard::PutNumber("TurnAmount", 2.0);

  // Elevators
  SmartDashboard::PutBoolean("Bin Elevator Bottom", false);
  SmartDashboard::PutBoolean("Bin Elevator Top", false);
  SmartDashboard::PutBoolean("Elevator Bottom", false);
  SmartDashboard::PutBoolean("Elevator Top", false);
}
void DentRobot::DisabledPeriodic(){
  Scheduler::GetInstance()->Run();
}
void DentRobot::AutonomousInit(){
  aut=new Autonomous(SmartDashboard::GetNumber("Auto Sequence"));
  printf("Enabling Auto Sequence %f\n", SmartDashboard::GetNumber("Auto Sequence"));
  if(aut != NULL){
    aut->Start();
  }
}
void DentRobot::AutonomousPeriodic(){
  printf("Running auto.\n");
  Scheduler::GetInstance()->Run();
}
void DentRobot::TeleopInit(){
  if (aut != NULL){
    aut->Cancel();
  }
}
void DentRobot::TeleopPeriodic(){
  Scheduler::GetInstance()->Run();
  // TODO: Calibrate 1.0 to the height we want the elevator to automatically raise
  if(elevator->GetUseEncoder()&&elevator->GetHeight()<=-1.0){
    // Raise the elevator if it dips below elevatorTop
    oi->raise->Start();
  }
}
void DentRobot::TestPeriodic(){
}
START_ROBOT_CLASS(DentRobot);
// vim: ts=2:sw=2:et
