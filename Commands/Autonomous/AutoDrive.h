#ifndef AUTODRIVE_H
#define AUTODRIVE_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class AutoDrive: public Command{
  private:
    double x, y;
  public:
    AutoDrive(double duration, double xtmp = 0.0, double ytmp = -0.75);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
