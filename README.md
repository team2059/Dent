# Dent
[The Hitchhikers](http://team2059.org) 2015 robot

### Features
#### Subsystems
+ [Mecanum drivetrain](Subsystems/Drivetrain.cpp)
+ [Collector](Subsystems/Collector.cpp) to collect totes in main elevator
+ [Internal elevator](Subsystems/Elevator.cpp) for totes
+ [External elevator](Subsystems/BinElevator.cpp) for bins or totes
+ [Pneumatics](Subsystems/Pneumatics.cpp) for opening/closing bin elevator arms (unused)

#### Sensors
+ [Ultrasonic](Subsystems/Collector.cpp#L9) to check if a tote is in the robot (unused)
+ [hall effect sensors](Subsystems/Elevator.cpp#L6-L8) to check the elevator's position

#### Automated Commands
+ [AutoDrive](Commands/Autonomous/AutoDrive.cpp) to drive forward without a joystick
+ [CollectTote](Commands/Autonomous/CollectTote.cpp) to drive forwards and roll in collectors in parallel
+ [ReleaseTote](Commands/Autonomous/ReleaseTote.cpp) to drive backwards and roll out collectors in parallel
+ [Turn](Commands/Autonomous/Turn.cpp) to turn the robot

### Running the code
#### Setup (for Linux)
+ Make sure you have the [toolchain](http://first.wpi.edu/FRC/roborio/toolchains/) installed
+ Edit the path of WPILib and the REMOTEIP on the Makefile
+ Run `make putkey` to put the public key on the rrio for faster deploying (optional)

#### Building
+ Run `make && make deploy`
+ Run `ssh admin@rrio-ip.local '/home/lvuser/FRCUserProgram'` to execute the program

### Usage
#### Left Joystick (USB 0)
+ X-Axis - Drive forwards and backwards
+ Y-Axis - Strafes left and right
+ Z-Axis - Turns left and right
+ Throttle - Adjusts collector speed
+ Button 1 - Collect totes
+ Button 2 - Eject totes

#### Right Joystick (USB 1)
+ Button 3 - Lowers bin elevator
+ Button 4 - Lowers main elevator
+ Button 5 - Raises bin elevator
+ Button 6 - Raises main elevator
+ Button 7 - Runs an elevator cycle
+ Button 12 - Cancel raising and lowering for both elevators

### Dashboard
#### Configuration
+ CodeVersion - The current version of the code
+ Auto Wait Time - The amount of time to wait for any autonomous to run (default: 2.0)
+ Two totes - Collect a second tote if using Auto Sequence 4 or 5 (default: true)
+ Three totes - Collect a third tote if using Auto Sequence 4 or 5 (default: false)
+ Auto Zone Distance - Amount of time in seconds to drive to the auto zone (default: 2.1)
+ Auto Tote Distance - Amount of time in seconds to drive to a second or third tote if using Auto Sequence 4, 5, or 7 (default: 0.5)
+ Auto Bin Distance - Amount of time in seconds to drive to a bin if using Auto Sequence 6 or 7 (default: 0.5)
+ TurnAmount - Amount of time in seconds to turn the robot 90 degrees
+ Elevator Bottom - Status of the bottom elevator sensor
+ Elevator Top - Status of the top elevator sensor
+ Auto Sequence - The sequence of autonomous to run

#### Autonomous
1. Drive to auto zone, turn
2. Lower BinElevator, collect bin, turn, drive to AutoZone, turn
3. Raise BinElevator, turn, drive to AutoZone, turn
4. Collect 1, 2, or 3 totes, turn, drive to AutoZone, turn
5. Same as auto 4, but navigate around bins (not implemented)
6. Collect 1 bin then 1 tote (not implemented)
7. Collect 3 totes, collect bin, drive to AutoZone (not implemented)
