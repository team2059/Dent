#ifndef AUTODRIVE_H
#define AUTODRIVE_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class AutoDrive: public Command{
  public:
    AutoDrive();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
// vim: ts2:sw=2:et
