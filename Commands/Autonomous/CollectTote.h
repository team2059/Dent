#ifndef COLLECTTOTE_H
#define COLLECTTOTE_H

#include "Commands/CommandGroup.h"
#include "../../DentRobot.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Collects one tote
 *
 * Rolls collector wheels in and drives forward in parallel
 */
class CollectTote: public CommandGroup{
  public:
    /**
     * @brief Constructs CollectTote
     * 
     * @param z Joystick z value (default: 0.0)
     */
    CollectTote(double z = 0.0);
};
#endif
// vim: ts=2:sw=2:et
