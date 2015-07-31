#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "Commands/CommandGroup.h"
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
 *
 * Sequence 4: Collect one, two, or three totes, drive to Auto Zone, release totes
 *
 * Sequence 5: Same as auto 4, but navigate around bins (not implemented)
 *
 * Sequence 6: Collect 1 bin and 1 tote (not implemented)
 *
 * Sequence 7: Same as auto 4, then collect bin, drive to auto zone, release totes (not implemented)
 *
 * Sequence 8: Use rear elevator to move tote
 *
 * Sequence 9: Use rear elevator to move bin
 */
class Autonomous: public CommandGroup {
 public:
  /**
   * @brief Constructs Autonomous
   *
   * @param seq The sequence to run (default: 0)
   */
  Autonomous(int seq = 0);
};
#endif
// vim: ts=2:sw=2:et
