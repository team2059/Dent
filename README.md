# Dent

Dent was designed to have a fast mecanum [drivetrain](Subsystems/Drivetrain.cpp) with ground clearance to traverse the scoring platforms with ease—all while carrying a stack of totes. A main [internal elevator](Subsystems/Elevator.cpp) lifts totes up to six high within the robot, allowing us to move quickly to anywhere on the field without tipping. The [intake system](Subsystems/Collector.cpp) features a ramp leading to the floor with an active roller pulling the totes up to two collector wheels on either side of the robot, both pulling the totes in, and centering them simultaneously. 

But Dent does not stop there; a [taller elevator](Subsystems/BinElevator.cpp) on the back of the robot allows us to lift either recycle containers or totes to a greater height. With this, we can create stacks both internally and externally, with each system providing a backup of the other in case anything breaks.

Dent is programmed in C++ and uses many sensors to determine what to do. An [ultrasonic sensor](Subsystems/Collector.cpp#L9) mounted on the back of the robot looking forward automatically slows down the collector wheels as the totes fly into the internal elevator. Homemade [hall effect sensors](Subsystems/Elevator.cpp#L6-L8) line the elevator shafts of both elevators, allowing the driver to raise totes and containers to pre-programmed heights. 

All aspects of Dent’s design come together to produce a robot ready to rank in qualifications, and still provide a fast and capable design for elimination rounds. With all parts made an code written for Dent in-house, this truly is a robot designed by, built by, and programmed by the students on Team 2059, [The Hitchhikers](http://team2059.org/).


### Controls
##### Driver Main Joystick (USB 0)
- X-Axis - Drive forwards and backwards
- Y-Axis - Strafes left and right
- Z-Axis - Turns left and right
- Throttle-Axis - Adjusts collector speed
- Button 1 - Collects totes
- Button 2 - Dispenses totes
- Button 7 - Enable robot test

##### Driver Secondary Joystick (USB 1)
- Button 3 - Lowers bin elevator
- Button 4 - Lowers tote elevator
- Button 5 - Raises bin elevator
- Button 6 - Raises tote elevator
- Button 7 - Opens bin arms
- Button 8 - Closes bin arms
- Button 12 - Universal cancel button