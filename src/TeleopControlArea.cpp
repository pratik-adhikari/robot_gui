#include "robot_gui/TeleopControlArea.h"

TeleopControlArea::TeleopControlArea()
    : linear_velocity_(0), angular_velocity_(0) {
  pub_ = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
  odom_sub_ = nh.subscribe<nav_msgs::Odometry>(
      "/odom", 10, &TeleopControlArea::odomCallback, this);
}

void TeleopControlArea::odomCallback(const nav_msgs::Odometry::ConstPtr &msg) {
  position_ = msg->pose.pose.position;
  orientation_ = msg->pose.pose.orientation;
}

void TeleopControlArea::update(cv::Mat &frame) {
  if (cvui::button(frame, 70, 230, "Forward")) {
    linear_velocity_ += 0.1;
  }
  if (cvui::button(frame, 70, 290, "Backward")) {
    linear_velocity_ -= 0.1;
  }
  if (cvui::button(frame, 10, 260, "Left")) {
    angular_velocity_ += 0.1;
  }
  if (cvui::button(frame, 150, 260, "Right")) {
    angular_velocity_ -= 0.1;
  }
  if (cvui::button(frame, 70, 260, "Stop")) {
    linear_velocity_ = 0;
    angular_velocity_ = 0;
  }

  geometry_msgs::Twist msg;
  msg.linear.x = linear_velocity_;
  msg.angular.z = angular_velocity_;
  pub_.publish(msg);

  cvui::printf(frame, 20, 330, 0.4, 0x0000FF, "Linear Vel: %.2f",
               linear_velocity_);
  cvui::printf(frame, 20, 350, 0.4, 0x0000FF, "Angular Vel: %.2f",
               angular_velocity_);

  cvui::printf(frame, 150, 330, 0.4, 0xFFFFFF, "Position X: %.2f", position_.x);
  cvui::printf(frame, 150, 345, 0.4, 0xFFFFFF, "Position Y: %.2f", position_.y);
  cvui::printf(frame, 150, 360, 0.4, 0xFFFFFF, "Position Z: %.2f", position_.z);
  cvui::printf(frame, 150, 375, 0.4, 0xFFFFFF, "Angular  Z: %.2f",
               orientation_.z);
}
