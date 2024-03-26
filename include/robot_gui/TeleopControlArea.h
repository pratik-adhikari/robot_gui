#ifndef TELEOP_CONTROL_AREA_H
#define TELEOP_CONTROL_AREA_H

#include "robot_gui/cvui.h"
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class TeleopControlArea {
public:
  TeleopControlArea();
  void update(cv::Mat &frame);

private:
  ros::NodeHandle nh;
  ros::Publisher pub_;
  double linear_velocity_;
  double angular_velocity_;

  ros::Subscriber odom_sub_;
  geometry_msgs::Point position_;
  geometry_msgs::Quaternion orientation_;

  void odomCallback(const nav_msgs::Odometry::ConstPtr &msg);
};

#endif // TELEOP_CONTROL_AREA_H
