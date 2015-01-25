#ifndef EJECT_H
#define EJECT_H

#include "Commands/Command.h"
#include "WPILib.h"

class Eject: public Command{
  public:
    Eject();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
