#ifndef CHECK_H
#define CHECK_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class Check: public CommandGroup{
  private:
    int motor;
  public:
    Check();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
