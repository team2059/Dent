#ifndef STOPCOMPRESSING_H
#define STOPCOMPRESSING_H

#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "Commands/Command.h"
#include "WPILib.h"

class StopCompressing: public Command{
  public:
    StopCompressing();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
