#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/ExampleSubsystem.h"
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
