#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Collector.h"
#include "Subsystems/Elevator.h"
#include "OI.h"
#include "WPILib.h"

class CommandBase: public Command {
  public:
    CommandBase(char const *name);
    CommandBase();
    static void init();
    static Drivetrain *drivetrain;
    static Collector *collector;
    static Elevator *elevator;
    static OI *oi;
};
#endif
// vim: ts2:sw=2:et
