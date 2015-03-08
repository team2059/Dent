#ifndef RELEASETOTE_H
#define RELEASETOTE_H

#include "Commands/CommandGroup.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Releases one tote
 *
 * Rolls collector wheels out and drives backwards in parallel
 */
class ReleaseTote: public CommandGroup{
  public:
    /**
     * @brief Constructs ReleaseTote
     */
    ReleaseTote();
};
#endif
// vim: ts=2:sw=2:et
