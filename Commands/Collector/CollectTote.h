#ifndef COLLECTTOTE_H
#define COLLECTTOTE_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class CollectTote: public Command{
  public:
    CollectTote();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
// vim: ts2:sw=2:et
