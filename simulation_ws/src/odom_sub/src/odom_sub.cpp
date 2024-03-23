#include <iostream>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2/LinearMath/Matrix3x3.h"

using std::placeholders::_1;


class OdomSub : public rclcpp::Node
{
public:
  OdomSub()
  : Node("odometry_subscriber")
  {
    subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/piracer/odom", 10, std::bind(&OdomSub::topic_callback, this, _1));
  }

private:
  void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
  {
    float x_pos = msg->pose.pose.position.x * 100;  // [cm]
    float y_pos = msg->pose.pose.position.y * 100;  // [cm]
    
    tf2::Quaternion q(
      msg->pose.pose.orientation.x,
      msg->pose.pose.orientation.y,
      msg->pose.pose.orientation.z,
      msg->pose.pose.orientation.w);
    tf2::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);  // [rad]

    float velocity = sqrt(pow(msg->twist.twist.linear.x, 2)
                        + pow(msg->twist.twist.linear.y, 2)) * 100;  // [cm/s]
  }

  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<OdomSub>());
  rclcpp::shutdown();
  return 0;
}