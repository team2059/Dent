#ifndef CHECKDRIVE_H
#define CHECKDRIVE_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief TODO
 */
class CheckDrive: public CommandGroup{
  private:
    int motor;
  public:
    /**
     * @brief TODO
     *
     * @param int
     */
    CheckDrive(int);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief TODO
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return TODO
     */
    bool IsFinished();
    /**
     * @brief TODO
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
