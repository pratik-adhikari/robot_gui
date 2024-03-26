#include "robot_gui/description_area.h"
#include <sstream>
#include <string>
#include <vector>

DescriptionArea::DescriptionArea() {
  ros::NodeHandle nh;
  topic_name = "/robot_info";
  sub_ = nh.subscribe<robotinfo_msgs::RobotInfo10Fields>(
      topic_name, 10, &DescriptionArea::msgCallback, this);
}

void DescriptionArea::msgCallback(
    const robotinfo_msgs::RobotInfo10Fields::ConstPtr &msg) {
  // single string from all the data
  std::stringstream info_stream;
  info_stream << "" << msg->data_field_01 << "\n"
              << "" << msg->data_field_02 << "\n"
              << "" << msg->data_field_03 << "\n"
              << "" << msg->data_field_04 << "\n"
              << "" << msg->data_field_05 << "\n"
              << "" << msg->data_field_06 << "\n"
              << "" << msg->data_field_07 << "\n"
              << "" << msg->data_field_08 << "\n"
              << "" << msg->data_field_09 << "\n"
              << "" << msg->data_field_10;
  data_string = info_stream.str();
}

std::vector<std::string> splitString(const std::string &str, char delimiter) {
  std::vector<std::string> lines;
  std::string line;
  std::istringstream stream(str);
  while (std::getline(stream, line, delimiter)) {
    lines.push_back(line);
  }
  return lines;
}

void DescriptionArea::run() {
  cv::Mat frame = cv::Mat(500, 300, CV_8UC3);
  cv::namedWindow(WINDOW_NAME);
  cvui::init(WINDOW_NAME);

  while (ros::ok()) {
    frame = cv::Scalar(49, 52, 49);
    cvui::window(frame, 15, 20, 250, 210, "Robot Info");

    // Split the data_string into lines
    std::vector<std::string> lines = splitString(data_string, '\n');
    int startY = 45;      // Starting Y position for the first line
    int lineSpacing = 15; // Vertical space between lines

    // Display each line
    for (const auto &line : lines) {
      cvui::text(frame, 25, startY, line, 0.4, 0xFFFFFF);
      startY += lineSpacing;
    }

    cvui::update();
    cv::imshow(WINDOW_NAME, frame);
    if (cv::waitKey(20) == 27)
      break;
    ros::spinOnce();
  }
}
