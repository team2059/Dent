#ifndef ROLLOUT_H
#define ROLLOUT_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class RollOut: public Command{
  public:
    RollOut();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
// vim: ts=2:sw=2:et
