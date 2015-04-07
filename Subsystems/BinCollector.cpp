#include "BinCollector.h"
#include "../RobotMap.h"

BinCollector::BinCollector(): Subsystem("BinCollector"){
  binCollectorMotor = new Servo(BINCOLLECTOR);
}
void BinCollector::InitDefaultCommand(){
}
void BinCollector::Set(double pos){
  binCollectorMotor->Set(pos);
  printf("BinCollector angle: %f\n", pos);
}
double BinCollector::Get(){
  return binCollectorMotor->Get();
}
// vim: ts=2:sw=2:et
