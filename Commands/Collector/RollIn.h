#ifndef ROLLIN_H
#define ROLLIN_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class RollIn: public Command{
  public:
    RollIn();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
// vim: ts=2:sw=2:et
