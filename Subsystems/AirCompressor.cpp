#include "AirCompressor.h"
#include "../RobotMap.h"

AirCompressor::AirCompressor() : Subsystem("AirCompressor") {
    compressher = new Compressor(31);
}
void AirCompressor::InitDefaultCommand() {
}
int AirCompressor::CreateCompressedAir() {
    printf("compressing and stuff\n");
    compressher->Start();
    return 0;
}
int AirCompressor::StopCreatingCompressedAir() {
    printf("not compressing and stuff\n");
    compressher->Stop();
    return 0;
}
