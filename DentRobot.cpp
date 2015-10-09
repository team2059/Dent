#include "DentRobot.h"
#include "OI.h"
#include "RobotMap.h"
#include "Commands/Autonomous/Autonomous.h"
OI* DentRobot::oi = NULL;
Collector* DentRobot::collector = NULL;
Drivetrain* DentRobot::drivetrain = NULL;
Elevator* DentRobot::elevator = NULL;
BinElevator* DentRobot::binElevator = NULL;
CommandGroup* DentRobot::aut = NULL;
Pneumatics* DentRobot::pneumatics = NULL;
BinCollector* DentRobot::binCollector = NULL;
DentRobot::DentRobot() {
  oi = new OI();
  collector = new Collector();
  drivetrain = new Drivetrain();
  elevator = new Elevator();
  binElevator = new BinElevator();
  pneumatics = new Pneumatics();
  binCollector = new BinCollector();
  //CameraServer::GetInstance()->SetQuality(25);
  //CameraServer::GetInstance()->StartAutomaticCapture("cam0");
  printf("The robot is on\n");
}
void DentRobot::RobotInit() {
  SmartDashboard::PutNumber("CodeVersion", CODE_VERSION);
  // Autonomous
  // Calibration
  // Amount to turn while collecting the initial tote in auto 4
  SmartDashboard::PutNumber("CollectToteTurn", 0.25);
  // Amount of time to collect a tote
  SmartDashboard::PutNumber("DriveTime", 1.3);
  // Sequence of autonomous command
  SmartDashboard::PutNumber("Auto Sequence", -1.0);
  SmartDashboard::PutNumber("Auto Wait Time", 0.5);
  // If the robot will be picking up three totes in sequence 3
  SmartDashboard::PutBoolean("Two totes", false);
  SmartDashboard::PutBoolean("Three totes", false);
  // Distance (in time) to auto zone
  SmartDashboard::PutNumber("Auto Zone Distance", 2.1);
  // Distance (in time) to auto tote (used in sequence 3)
  SmartDashboard::PutNumber("Two Tote Distance", 1.0);
  SmartDashboard::PutNumber("Three Tote Distance", 2.5);
  SmartDashboard::PutNumber("Auto Tote Distance", 0.5);
  SmartDashboard::PutNumber("TurnAmount", 2.6);
  // Elevators
  SmartDashboard::PutBoolean("Elevator Bottom", false);
  SmartDashboard::PutBoolean("Elevator Top", false);
  //Gyro
  SmartDashboard::PutNumber("Gyro kP", -0.02);
  printf("Starting compressor\n");
  pneumatics->SetCompressorEnabled(true);
  pneumatics->SetElevatorArmOpen(false);
}
void DentRobot::DisabledPeriodic() {
  Scheduler::GetInstance()->Run();
}
void DentRobot::AutonomousInit() {
  aut = new Autonomous(SmartDashboard::GetNumber("Auto Sequence"));
  printf("Enabling Auto Sequence %f\n", SmartDashboard::GetNumber("Auto Sequence"));
  if(aut != NULL) {
    aut->Start();
  }
}
void DentRobot::AutonomousPeriodic() {
  printf("Running auto.\n");
  Scheduler::GetInstance()->Run();
}
void DentRobot::TeleopInit() {
  if(aut != NULL) {
    aut->Cancel();
  }
}
void DentRobot::TeleopPeriodic() {
  Scheduler::GetInstance()->Run();
  SmartDashboard::PutNumber("CollectorThrottle", oi->GetLeftThrottle());
}
void DentRobot::TestPeriodic() {}
START_ROBOT_CLASS(DentRobot);
// vim: ts=2:sw=2:et
