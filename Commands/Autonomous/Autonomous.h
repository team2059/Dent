#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "Commands/CommandGroup.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief The autonomous period of the robot
 *
 * Contains three sequences selectable from the SmartDashboard
 * All sequences will wait for the SmartDashboard value "Auto Wait Time"
 * 
 * Sequence 0: Used for testing only
 *
 * Sequence 1: Drives forward "Auto Zone Distance" at -0.8 power
 *
 * Sequence 2: Collects a tote, turns, then drives to the auto zone
 *
 * Sequence 3: Collects two or three totes then drives to auto zone
 */
class Autonomous: public CommandGroup{
  public:
    /**
     * @brief Constructs Autonomous
     *
     * @param seq The sequence to run
     */
    Autonomous(int seq=0);
};
#endif
// vim: ts=2:sw=2:et
