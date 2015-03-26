#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

#define CODE_VERSION 2.1

// Elevator
#define ELEVATOR_CAN 1
#define ELEVATOR_BOTTOM_DIO 9
#define ELEVATOR_MIDDLE_DIO 8
#define ELEVATOR_TOP_DIO 7
#define ELEVATOR_ENCODERA 4
#define ELEVATOR_ENCODERB 9

// BinElevator
#define BINELEVATOR_CAN 10
#define BINELEVATOR_BOTTOM_DIO 6
#define BINELEVATOR_COLELCT_BIN_DIO 7
#define BINELEVATOR_TOP_DIO 12
#define BINELEVATOR_ENCODERA 10
#define BINELEVATOR_ENCODERB 11
#define BINELEVATOR_SOLDENOID_ONE   6
#define BINELEVATOR_SOLDENOID_TWO   7

// Drivetrain
#define DRIVE_FRONT_LEFT_CAN 8
#define DRIVE_BACK_LEFT_CAN 3
#define DRIVE_FRONT_RIGHT_CAN 4
#define DRIVE_BACK_RIGHT_CAN 5
#define DRIVE_GYRO_ANALOG 0

// Collector
#define COLLECTOR_RAMP_CAN 7
#define COLLECTOR_LEFT_CAN 2
#define COLLECTOR_BOTTOM_CAN 11
#define COLLECTOR_RIGHT_CAN 9
#define COLLECTOR_SONAR_ANALOG 3

#endif
// vim: ts=2:sw=2:et
