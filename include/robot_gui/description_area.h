#ifndef DESCRIPTION_AREA_H
#define DESCRIPTION_AREA_H

#define CVUI_IMPLEMENTATION
#include "robot_gui/cvui.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <sstream>
#include <string>
#include <vector>

#define WINDOW_NAME "Robot GUI"

class DescriptionArea {
public:
  DescriptionArea();
  void update(cv::Mat &frame);

private:
  ros::NodeHandle nh;
  ros::Subscriber sub_;
  std::string topic_name;
  std::string data_string;
  void msgCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &msg);
  std::vector<std::string> splitString(const std::string &str, char delimiter);
};

#endif // DESCRIPTION_AREA_H
