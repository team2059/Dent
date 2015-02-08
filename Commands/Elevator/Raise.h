#ifndef RAISE_H
#define RAISE_H

#include "Commands/Command.h"
#include "WPILib.h"

class Raise: public Command{
  public:
    Raise();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
// vim: ts2:sw=2:et
