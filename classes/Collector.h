#ifndef __COLLECTOR_H__
#include <WPILib.h>
#define __COLLECTOR_H__
//#include ""
class DentCollector{
  private:
    Talon *collectorLeft, *collectorRight, *raiserLeft, *raiserRight;
  public:
    DentCollector(int, int, int, int);
    void Collect(float);
    void Raise(float);
    void Rest();
};
#endif
// vim: ts=2:sw=2:et
