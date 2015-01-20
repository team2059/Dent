#include "AirCompressor.h"
#include "../RobotMap.h"

AirCompressor::AirCompressor() : Subsystem("AirCompressor") {
    compressher = new Compressor(31);
}
void AirCompressor::InitDefaultCommand() {
}
void AirCompressor::CreateCompressedAir() {
    compressher->Start();
}
void AirCompressor::StopCreatingCompressedAir() {
    compressher->Stop();
}
