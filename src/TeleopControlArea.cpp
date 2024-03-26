#include "robot_gui/TeleopControlArea.h"

TeleopControlArea::TeleopControlArea()
    : linear_velocity_(0), angular_velocity_(0) {
  pub_ = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
}

void TeleopControlArea::update(cv::Mat &frame) {
  if (cvui::button(frame, 70, 250, "Forward")) {
    linear_velocity_ += 0.1; // Increase linear velocity
  }
  if (cvui::button(frame, 70, 310, "Backward")) {
    linear_velocity_ -= 0.1; // Decrease linear velocity
  }
  if (cvui::button(frame, 10, 280, "Left")) {
    angular_velocity_ += 0.1; // Increase angular velocity (turn left)
  }
  if (cvui::button(frame, 130, 280, "Right")) {
    angular_velocity_ -= 0.1; // Decrease angular velocity (turn right)
  }
  if (cvui::button(frame, 70, 280, "Stop")) {
    linear_velocity_ = 0;  // Stop linear movement
    angular_velocity_ = 0; // Stop angular movement
  }

  geometry_msgs::Twist msg;
  msg.linear.x = linear_velocity_;
  msg.angular.z = angular_velocity_;
  pub_.publish(msg);
}
