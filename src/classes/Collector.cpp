#include "Collector.h"
DentCollector::DentCollector(int fl, int fr, int rl, int rr){
  frontLeft = new Talon(fl);
  frontRight = new Talon(fr);
  raiserLeft = new Talon(rl);
  raiserRight = new Talon(rr);
}
void DentCollector::Collect(int power){
  frontLeft->Set(power);
  frontRight->Set(power);
}
void DentCollector::Raise(int power){
  raiserLeft->Set(power);
  raiserRight->Set(power);
}
void DentCollector::Rest(){
  raiserLeft->Set(0);
  raiserRight->Set(0);
  frontLeft->Set(0);
  frontRight->Set(0);
}
// vim: ts=2:sw=2:et
