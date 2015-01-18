#ifndef DRIVE_H
#define DRIVE_H

#include "../CommandBase.h"
#include "../DentRobot.h"
#include "Commands/Command.h"
#include "WPILib.h"

class Drive: public Command{
  public:
    Drive();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
