
## Overview

 The package allows a simulated robot to generate and reach random goals in a 2d space in ros stage.

### Building from source

To build from source, clone the latest version from this repository into your catkin workspace:

	cd catkin_workspace/src
	git clone 
	cd ../
	catkin_make

Remember to make scripts executable, in the scripts folder use the following commands:

	chmod +x goal_client.py
	chmod +x goal_client_base.py
	chmod +x goal_client_server.py
	
Check files permission with:
	
	ls -l

## Usage

To run the solution you can use the solution.launch file:

	roslaunch assignment1_solution solution.launch

## Launch files

* **solution.launch** This launch file will starts 3 nodes: stage, server, client.

	- **'stage'** Spawn the robot in the ros stage environment.

	- **'server'** Start a service server node which will generate a random goal between (-6,6) when requested.

	- **'client'** Start service client that asks the server for a goal and then commands the robot to reach it. Respawn and output are set to True, so that the once a goal is reached the client will send another request and the output will be printed to screen.

## Custom Nodes

### Server

Waits for requests in order to generate random x and y coordinates in the interval (-6, 6)

#### Subscribed Topics

None

#### Published Topics

None

#### Services

* **`goal_generator`** ([assignment1_solution/goal])

	Returns a random goal in x and y coordinates in the interval (-6, 6). The service takes as a request a 		bool, if it is True it generates the random goal responding with two floats: x and y. If the request is 	False than the goal is set to x=0, y=0, the robot comes back to the starting position.

### Client

Asks to the server for a random goal. Moves the robot using a specific law of motion which is described in the graphs below.

![](it.plot.png)

- ![#f03c15](https://via.placeholder.com/15/f03c15/000000?text=+) Displacement function
- ![#1589F0](https://via.placeholder.com/15/1589F0/000000?text=+) Velocity function
- ![#c5f015](https://via.placeholder.com/15/c5f015/000000?text=+) Acceleration function

The function has been developed with the intent to have 0 initial and final velocities and accelerations for both axis.

#### Subscribed Topics

* **`/odom`** ([nav_msgs.msg/Odometry])

	The current position of the robot.

#### Published Topics

* **`/cmd_vel`** ([geometry_msgs.msg/Twist])

	The current robot velocities.

#### Services

* **`goal_generator`** ([assignment1_solution/goal])

	Request goal

![rosgraph](https://user-images.githubusercontent.com/77781922/115150623-bf2e9780-a058-11eb-9505-58a8d85e660a.png)
