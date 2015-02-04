#include "AirCompressor.h"
#include "../RobotMap.h"

AirCompressor::AirCompressor() : Subsystem("AirCompressor") {
  compressor = new Compressor(COMPRESSOR_CAN);
}
void AirCompressor::InitDefaultCommand() {
}
void AirCompressor::StartCompressing() {
  if(compressor->Enabled()){
    printf("Starting compressor\n");
    compressor->Start();
  }
}
void AirCompressor::StopCompressing() {
  if(compressor->Enabled()){
    printf("Stopping compressor\n");
    compressor->Stop();
  }
}
