#ifndef RollVar_H
#define RollVar_H

#include "Commands/Command.h"
#include "../../DentRobot.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Rolls collector motors based on button 7
 */
class RollVar: public Command{
  private:
    double speed; //<! Speed control of the collector
  public:
    /**
     * @brief Constructs RollVar
     *
     * @param speedVal Speed control of the collector
     */
    RollVar(double speedVal);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Rolls the collector motors in variable speeds
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return True only if the timeout was reached
     */
    bool IsFinished();
    /**
     * @brief Sets the collector to stop
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
