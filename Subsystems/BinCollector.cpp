#include "BinCollector.h"
#include "../RobotMap.h"

BinCollector::BinCollector(): Subsystem("BinCollector") {
  leftBinCollectorMotor = new CANTalon(BINCOLLECTOR_LEFT_CAN);
  rightBinCollectorMotor = new CANTalon(BINCOLLECTOR_RIGHT_CAN);
}
void BinCollector::InitDefaultCommand() {}
void BinCollector::MoveArms(double speed) {
  leftBinCollectorMotor->Set(speed);
  rightBinCollectorMotor->Set(-speed);
}
// vim: ts=2:sw=2:et
