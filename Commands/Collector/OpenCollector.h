#ifndef OPENCOLLECTOR_H
#define OPENCOLLECTOR_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class OpenCollector: public Command{
  public:
    OpenCollector();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
// vim: ts=2:sw=2:et
