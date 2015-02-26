#ifndef AUTODRIVE_H
#define AUTODRIVE_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class AutoDrive: public Command{
  private:
    double speed, strafe;
  public:
    AutoDrive(double);
    AutoDrive(double, double,double);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
