#ifndef LOWER_H
#define LOWER_H

#include "../CommandBase.h"
#include "WPILib.h"

class Lower: public CommandBase{
public:
	Lower();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
