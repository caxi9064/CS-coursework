"""lab3 controller."""
# Copyright University of Colorado Boulder 2022
# CSCI 3302 "Introduction to Robotics" Lab 3 Base Code.

from controller import Robot, Motor
import math

# Robot Parameters
MAX_SPEED = 6.67 # [rad/s]
MAX_SPEED_MS = 0.22 # [m/s]
AXLE_LENGTH = 0.16 # [m


MOTOR_LEFT = 0 # Left wheel index
MOTOR_RIGHT = 1 # Right wheel index

# create the Robot instance.
robot = Robot()

# get the time step of the current world.
timestep = int(robot.getBasicTimeStep())

# The Turtlebot robot has two motors
part_names = ("left wheel motor", "right wheel motor")

# Set wheels to velocity control by setting target position to 'inf'
robot_parts = list(map(lambda name: robot.getDevice(name), part_names))
for part in robot_parts:
    part.setPosition(math.inf)

# Odometry
pose_x     = 0
pose_y     = 0
pose_theta = 0

# Rotational Motor Velocity [rad/s]
vL = 0
vR = 0

def inverse_kinematics(dx, theta):
    L = dx - theta * AXLE_LENGTH / 2
    R = dx + theta * AXLE_LENGTH / 2
    return L, R

# TODO
# Create you state and goals (waypoints) variable here
# You have to MANUALLY figure out the waypoints, one sample is provided for you in the instructions
checkpoint = 0
waypoints = [
    (0, 0, 0),
]

def add_waypoint(x, y):
    global waypoints
    previous = waypoints[len(waypoints)-1]
    bearing = math.atan2(y - previous[1],x - previous[0])
    previous = (previous[0], previous[1],bearing)
    waypoints.append((x, y, 0))

add_waypoint(1, -0.5)
add_waypoint(2, -0.5)
add_waypoint(3, 1)
add_waypoint(5, 1)

def target_pos():
    target_x, target_y, target_theta = waypoints[checkpoint]
    return target_x, target_y, target_theta

def calculate_position_error():
    target_x, target_y, _  = target_pos()
    return math.sqrt((pose_x - target_x)**2 + (pose_y - target_y)**2)

def calculate_bearing_error():
    target_x, target_y, _ = target_pos()
    dx, dy = target_x - pose_x, target_y - pose_y
    theta = math.atan2(dy,dx)
    return theta - pose_theta

def calculate_heading_error():
    _, _, target_theta = target_pos()
    return target_theta - pose_theta
    
def update_odometry():
    """"calcate the position of the epuck robot based on wheel speed."""
    # global variables to store/update pose information
    global pose_x, pose_y, pose_theta
    
    timestep_s = timestep / 1000 # timestep in seconds

    # wheel velociity in meters per second
    wheel_vel_L = (vL / MAX_SPEED) * MAX_SPEED_MS
    wheel_vel_R = (vR / MAX_SPEED) * MAX_SPEED_MS

    # distance moved by wheel
    wheel_diff_L = wheel_vel_L * timestep_s
    wheel_diff_R = wheel_vel_R * timestep_s

    # calculate and update based on equation 3.33
    pose_x += math.cos(pose_theta) * (wheel_diff_L / 2 + wheel_diff_R / 2)
    pose_y += math.sin(pose_theta) * (wheel_diff_L / 2 + wheel_diff_R / 2)

    # calculate and update theta on equation 3.32
    pose_theta += (wheel_diff_R - wheel_diff_L) / AXLE_LENGTH
        
def clamp(value, min_value, max_value):
    return max(min(value, max_value), min_value)

def stop():
    robot_parts[MOTOR_LEFT].setVelocity(0)
    robot_parts[MOTOR_RIGHT].setVelocity(0)

def print_pos():
    print(pose_x, pose_y, pose_theta, end=' ')

def balance_values(vL, vR):
    '''normalize vL, vR to -1 to 1'''
    ratio = vL / vR
    max_value = max(abs(vL), abs(vR))
    #if max_value < 1:
    #    return vL, vR
    vR = vR / max_value
    vL = vR * ratio
    return vL, vR

def navigate():
    pass
    
while robot.step(timestep) != -1:
    # calculate feedback values
    rho = calculate_position_error()
    alpha = calculate_bearing_error()
    eta = calculate_heading_error()

    # check if it has hit the waypoint
    if rho < 0.05 and abs(eta) < math.pi / 6:
        print(f'hit waypoint {checkpoint}')
        checkpoint += 1
        if checkpoint >= len(waypoints):
            print('robot program finished')
            stop()
            break
        else:
            print(f'target waypoint: {target_pos()}')
            stop()
            continue
    
    # calculate wheel rotational velocity
    dx = 0.2 * rho
    dtheta = 1 * alpha + 0.3 * eta
    vL, vR = inverse_kinematics(dx, dtheta)
    vL, vR = balance_values(vL, vR) # normalize values between -1 to 1

    vL = vL * MAX_SPEED * 0.5 # convert to rotational vel
    vR = vR * MAX_SPEED * 0.5 # convert to rotational vel

    vL = clamp(vL, -MAX_SPEED, MAX_SPEED)
    vR = clamp(vR, -MAX_SPEED, MAX_SPEED)

    # odometry
    update_odometry()
    
    ########## Do not change ######################
    # Bound pose_theta between [-pi, 2pi+pi/2]
    # Important to not allow big fluctuations between timesteps (e.g., going from -pi to pi)
    if pose_theta > 6.28+3.14/2: pose_theta -= 6.28
    if pose_theta < -3.14: pose_theta += 6.28
    ###############################################

    # Set robot motors to the desired velocities
    robot_parts[MOTOR_LEFT].setVelocity(vL)
    robot_parts[MOTOR_RIGHT].setVelocity(vR)