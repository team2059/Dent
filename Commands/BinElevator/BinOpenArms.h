#ifndef BINOPENARMS_H
#define BINOPENARMS_H

#include "Commands/Command.h"
#include "WPILib.h"

class BinOpenArms: public Command{
  public:
    BinOpenArms();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
// vim: ts=2:sw=2:et
