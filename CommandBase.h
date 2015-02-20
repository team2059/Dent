#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Collector.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/BinElevator.h"
#include "Subsystems/Pneumatics.h"
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
    static BinElevator *binElevator;
    static Pneumatics *pneumatics;
    static OI *oi;
};
#endif
// vim: ts=2:sw=2:et
