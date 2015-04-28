#ifndef ELEVATORCYCLE_H

#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Completes one cycle with the main elevator
 *
 * Completes a cycle by lowering the elevator to the bottom sensor,
 * then raising the elevator the the top sensor.
 * Timeouts are still in place in the event of a sensor failure.
 */

class ElevatorCycle: public CommandGroup{
  public:
    /**
     * @brief Constructs ElevatorCycle
     */
    ElevatorCycle();
};
#endif
// vim: ts=2:sw=2:et
