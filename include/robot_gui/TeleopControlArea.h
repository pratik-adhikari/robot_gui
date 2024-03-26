#ifndef TELEOP_CONTROL_AREA_H
#define TELEOP_CONTROL_AREA_H

#include "robot_gui/cvui.h"
#include <geometry_msgs/Twist.h>
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
};

#endif // TELEOP_CONTROL_AREA_H
