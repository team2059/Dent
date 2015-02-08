#ifndef CLOSECOLLECTOR_H
#define CLOSECOLLECTOR_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class CloseCollector: public Command{
  public:
    CloseCollector();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
// vim: ts2:sw=2:et
