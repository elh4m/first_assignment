#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
#include "my_srv/random_target.h"
#include <sstream>
#include <iostream>
#include <math.h>

ros::Publisher chat_pub; 

ros::ServiceClient client; 

my_srv::random_target target; // random_target server 
geometry_msgs::Point T_vel; // Target point position

void positionCallback(const nav_msgs::Odometry::ConstPtr& od)
{
  int k = 2; // velocity constant
  geometry_msgs::Point p_vel;
  geometry_msgs::Twist vel;

  // read robot postion (x,y)
  p_vel.x = od->pose.pose.position.x; 
  p_vel.y = od->pose.pose.position.y;
	
// Check the difference between the target and robot position
// if the diffenrence was less than 0.1 target is reached!
// then receive a new target position

if( fabs(T_vel.x - p_vel.x) < 0.1 && fabs(T_vel.y - p_vel.y) < 0.1 )
 {	
	// call service to get a random target
	client.call(target); 

	// update Target_Position
	T_vel.x = target.response.pos_x;
  	T_vel.y = target.response.pos_y;

	// print Target_Position on terminal
	ROS_INFO("Target position [%lf, %lf]", T_vel.x , T_vel.y);
 }
  
  // set linear velocities 
  vel.linear.x = k*(T_vel.x - p_vel.x);
  vel.linear.y = k*(T_vel.y - p_vel.y);
  
  // publish velocity values
  chat_pub.publish(vel);

}


int main(int argc, char **argv)
{
  // Initialize the node, setup the NodeHandle for handling the communication with the ROS
  // system
  ros::init(argc, argv, "assignment1");
  ros::NodeHandle n; 

  // define the client to receive random target from the server
  client = n.serviceClient<my_srv::random_target>("/target");
  client.call(target);

  T_vel.x = target.response.pos_x; // get the random_target x value
  T_vel.y = target.response.pos_y; // get the random_target y value

  // print value on terminal
  ROS_INFO("Target position [%lf, %lf]", T_vel.x , T_vel.y); 

  // define the subscriber to the robot Odometry (position)
  ros::Subscriber pose_sub = n.subscribe("/odom", 1000, positionCallback);

  // define the publisher to publish robot Twist (speed values)
  chat_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  
  ros::spin();

  return 0;
}
