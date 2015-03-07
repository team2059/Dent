#ifndef LOWER_H
#define LOWER_H

#include "Commands/Command.h"
#include "WPILib.h"

class Lower: public Command{
  public:
    Lower(double timeout=3.0);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
