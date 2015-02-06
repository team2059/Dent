#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class Autonomous: public CommandGroup{
  public:
    Autonomous();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
