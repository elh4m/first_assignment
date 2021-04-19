
## Overview

 The package allows a simulated robot to generate and reach random goals in a 2d space in ros stage.

### Building from source

To build from source, clone the latest version from this repository into your catkin workspace:

	cd catkin_workspace/src
	git clone 
	cd ../
	catkin_make


Check files permission with:
	
	ls -l


### Server

Waits for requests in order to generate random x and y coordinates in the interval (-6, 6)



#### Subscribed Topics

* **`/odom`** ([nav_msgs.msg/Odometry])

	The current position of the robot.

#### Published Topics

* **`/cmd_vel`** ([geometry_msgs.msg/Twist])

	The current robot velocities.

#### Services

* **`goal_generator`** ([assignment1/goal])

	Request goal
	
#### how to run the code

type these commands in your terminal:

rosrun my_srv my_srv

then :

rosrun assignment1 assignment1
rqt_graph for displaying a graph with all the relationships between nodes


![rosgraph](https://user-images.githubusercontent.com/77781922/115150623-bf2e9780-a058-11eb-9505-58a8d85e660a.png)
