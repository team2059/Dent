#ifndef BINLOWER_H
#define BINLOWER_H

#include "Commands/Command.h"
#include "WPILib.h"

class BinLower: public Command{
  public:
    BinLower();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et