#ifndef AIRCOMPRESSOR_H
#define AIRCOMPRESSOR_H

#include "WPILib.h"
class AirCompressor: public Subsystem
{
  private:
    Compressor *compressor;
  public:
    AirCompressor();
    void InitDefaultCommand();
    void StartCompressing();
    void StopCompressing();
};
#endif
