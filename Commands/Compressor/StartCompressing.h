#ifndef STARTCOMPRESSING_H
#define STARTCOMPRESSING_H

#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "Commands/Command.h"
#include "WPILib.h"

class StartCompressing: public Command{
  public:
    StartCompressing();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
