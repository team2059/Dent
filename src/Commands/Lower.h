#ifndef LOWER_H
#define LOWER_H

#include "Commands/Command.h"
#include "WPILib.h"

class Lower: public Command{
  public:
    Lower();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
