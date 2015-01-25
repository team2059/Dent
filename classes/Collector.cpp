#include "Collector.h"
DentCollector::DentCollector(int fl, int fr, int rl, int rr){
  collectorLeft = new Talon(fl);
  collectorRight = new Talon(fr);
  raiserLeft = new Talon(rl);
  raiserRight = new Talon(rr);
}
void DentCollector::Collect(float power){
  collectorLeft->Set(power);
  collectorRight->Set(power);
}
void DentCollector::Raise(float power){
  raiserLeft->Set(power);
  raiserRight->Set(power);
}
void DentCollector::Rest(){
  raiserLeft->Set(0);
  raiserRight->Set(0);
  collectorLeft->Set(0);
  collectorRight->Set(0);
}
// vim: ts=2:sw=2:et
