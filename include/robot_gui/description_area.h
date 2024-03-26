#pragma once

#define CVUI_IMPLEMENTATION
#include "robot_gui/cvui.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class DescriptionArea {
public:
  DescriptionArea();
  void run();

protected:
  ros::Subscriber sub_;
  robotinfo_msgs::RobotInfo10Fields data;
  std::string topic_name;
  std::string data_string;

  void msgCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &msg);
  const std::string WINDOW_NAME = "Robot Information";
};
