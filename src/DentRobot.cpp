#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Drive.h"
#include "Commands/Collect.h"
#include "Commands/Eject.h"
#include "Commands/Raise.h"
#include "Commands/Lower.h"
class DentRobot: public IterativeRobot {
private:
  Command *autonomousCommand = NULL;
  LiveWindow *lw;
  void RobotInit() {
    CommandBase::init();
    lw = LiveWindow::GetInstance();
  }
  void DisabledPeriodic() {
    Scheduler::GetInstance()->Run();
  }
  void AutonomousInit() {
    if(autonomousCommand != NULL) {
      autonomousCommand->Start();
    }
  }
  void AutonomousPeriodic() {
    Scheduler::GetInstance()->Run();
  }
  void TeleopInit() {
    if(autonomousCommand != NULL) {
      autonomousCommand->Cancel();
    }
  }
  void TeleopPeriodic() {
    Scheduler::GetInstance()->Run();
  }
  void TestPeriodic() {
    lw->Run();
  }
};
START_ROBOT_CLASS(DentRobot);
