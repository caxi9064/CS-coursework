"""lab1_controller controller."""
"""
Implement a state machine-based controller that recreates the following behavior:
The robot drives forward. 
The robot continues until its sensor reads a value from one of its front distance sensors showing that it’s within about 0.05m of the detected object. 
Once at that distance, the robot turns 180 degrees and drives until its front sensor says it is within about 0.05m of another object. 
Once arriving at within 0.05m of the object, it will rotate clockwise until the left distance sensor (ps5) reads <0.05m. 
Finally, it will continually drive forward as long as the left distance sensor reads <0.05m, otherwise it will stop in place and wait forever.
"""

# You may need to import some classes of the controller module. Ex:
#  from controller import Robot, Motor, DistanceSensor
from controller import Robot

# create the Robot instance.
# api: https://cyberbotics.com/doc/guide/epuck?tab-language=python
robot = Robot()

MAX_SPEED = 6.28

# get the time step of the current world.
timestep = int(robot.getBasicTimeStep())
print(timestep)

# You should insert a getDevice-like function in order to get the
# instance of a device of the robot. Something like:
#  motor = robot.getDevice('motorname')
#  ds = robot.getDevice('dsname')
#  ds.enable(timestep)
leftSensor = robot.getDevice('ps5')
leftSensor.enable(timestep)
frontSensor = robot.getDevice('ps7')
frontSensor.enable(timestep)
leftMotor = robot.getDevice('left wheel motor')
rightMotor = robot.getDevice('right wheel motor')


# set up the motor speeds at 10% of the MAX_SPEED.
leftMotor.setVelocity(0.5 * MAX_SPEED)
rightMotor.setVelocity(0.5 * MAX_SPEED)

def distanceLess5cm(sensor):
    return sensor.getValue() > 150
  
class MoveForward:
    def __init__(self):
        print('forward')
        
    def update(self):
        # move forwards
        leftMotor.setPosition(float('inf'))
        rightMotor.setPosition(float('inf'))
        if distanceLess5cm(frontSensor):
            return Turn180()
        else:
            return self

class Turn180:
    def __init__(self):
        self.time = 0
        print('180')
        
        
    def update(self):
        self.time += timestep
        leftMotor.setPosition(float('inf'))
        rightMotor.setPosition(-100000000)
        if self.time < 1550:
            return self
        else:
            return MoveForward2()
            
class MoveForward2:
    def __init__(self):
        print('forward 2')
        
    def update(self):
        leftMotor.setPosition(float('inf'))
        rightMotor.setPosition(float('inf'))
        if distanceLess5cm(frontSensor):
            return TurnClockwise()
        return self

class TurnClockwise():
    def __init__(self):
        print('clockwise')
        
    def update(self):
        leftMotor.setPosition(float('inf'))
        rightMotor.setPosition(-100000000)
        
        # until ps5 < 0.05m
        if distanceLess5cm(leftSensor):
            return MoveForward3()
        return self
      
class MoveForward3:
    def __init__(self):
        print('forward 2')
        
    def update(self):
        leftMotor.setPosition(float('inf'))
        rightMotor.setPosition(float('inf'))
        if not distanceLess5cm(leftSensor):
            return Stop()
        return self
      
class Stop:
    def __init__(self):
        print('stop')
        
    def update(self):
        leftMotor.setVelocity(0)
        rightMotor.setVelocity(0)
        return self

      
state = MoveForward()
# Main loop:
# - perform simulation steps until Webots is stopping the controller
while robot.step(timestep) != -1:
    # Read the sensors:
    # Enter here functions to read sensor data, like:
    #  val = ds.getValue()
    state = state.update() # robot drives forward
    

    # Process sensor data here.

    # Enter here functions to send actuator commands, like:
    #  motor.setPosition(10.0)
    pass

# Enter here exit cleanup code.
