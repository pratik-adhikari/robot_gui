#include "robot_gui/TeleopControlArea.h"
#include "robot_gui/description_area.h"
#include "ros/ros.h"

#define WINDOW_NAME "Robot GUI"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_gui");

  // Initialize GUI components
  DescriptionArea descriptionArea;
  TeleopControlArea teleopControlArea;

  // Initialize OpenCV window
  cv::Mat frame = cv::Mat(500, 300, CV_8UC3); // Adjust the size as necessary
  cv::namedWindow(WINDOW_NAME);
  cvui::init(WINDOW_NAME);

  while (ros::ok()) {
    // Clear the frame with a background color
    frame = cv::Scalar(49, 52, 49);

    // Update and render the DescriptionArea
    descriptionArea.update(frame);

    // Update and render the TeleopControlArea
    teleopControlArea.update(frame);

    // Update the GUI
    cvui::update();
    cv::imshow(WINDOW_NAME, frame);

    if (cv::waitKey(20) == 27) {
      break; // Exit on ESC key
    }

    ros::spinOnce();
  }

  return 0;
}
