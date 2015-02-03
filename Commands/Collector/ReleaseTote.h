#ifndef RELEASETOTE_H
#define RELEASETOTE_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class ReleaseTote: public Command{
  public:
    ReleaseTote();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
