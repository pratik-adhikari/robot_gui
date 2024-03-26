#include "robot_gui/description_area.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_gui");
  DescriptionArea descriptionArea;
  descriptionArea.run();
  return 0;
}
