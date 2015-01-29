#ifndef AIRCOMPRESSOR_H
#define AIRCOMPRESSOR_H

#include "WPILib.h"
class AirCompressor: public Subsystem
{
  private:
      Compressor *compressher;
  public:
    AirCompressor();
    void InitDefaultCommand();
    int CreateCompressedAir();
    int StopCreatingCompressedAir();
};
#endif
