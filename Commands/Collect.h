#ifndef COLLECT_H
#define COLLECT_H

#include "Commands/Command.h"
#include "WPILib.h"

class Collect: public Command{
  public:
    Collect();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
