#ifndef __COLLECTOR_H__
#include <WPILib.h>
#define __COLLECTOR_H__
//#include ""
class DentCollector{
  private:
    Talon *frontLeft, *frontRight, *raiserLeft, *raiserRight;
  public:
    DentCollector(int, int, int, int);
    void Collect(int);
    void Raise(int);
    void Rest();
};
#endif
// vim: ts=2:sw=2:et
