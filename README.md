
# first_assignment Elham Mohammadi 5073904

 The package allows a simulated robot to generate and reach random goals in a 2d space in ros stage.
 
# fisrt-assignment
a pakage for research track course

## General info
The assignment is to control a holonomic robot in 2d space with a simple 2d simulator.
## Algorithm
-  Set a random target in the interval [-6.0, 6.0]
-  Check the distance between target and robot position
-  IF distance is larger than 0.1 -> update x,y speed value -> Go to step 2.
-  Else -> Go to step 1.
## content of package:
## node
First node: (assignment1)
```
ROS publisher: publishing the robot speed
```
ROS client: receiving a random target
```
Second node: (my_srv)
```
ROS server: Service Server replys to the client with a random target
## Costum service
Random_Target service: return two random positions between [-6.0, 6.0]
## How to run the code

Build the packages 'catkin_make' in the your workspace
```
Refresh 'rospack profile'
```
Run the simulator
```
$ roscore &
```
$ rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
```
Run the service node
```
$ rosrun my_srv my_srv
```
Run the First node
```
$ rosrun assignment1 assignment1


![rosgraph](https://user-images.githubusercontent.com/77781922/115150623-bf2e9780-a058-11eb-9505-58a8d85e660a.png)
