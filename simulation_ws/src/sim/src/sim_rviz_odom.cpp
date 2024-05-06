#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2/LinearMath/Matrix3x3.h"

using std::placeholders::_1;


class SimRvizOdometry : public rclcpp::Node
{
public:
  SimRvizOdometry()
  : Node("sim_rviz_odometry")
  {
    subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/piracer/odom", 10, std::bind(&SimRvizOdometry::topic_callback, this, _1));

    publication_ = this->create_publisher<nav_msgs::msg::Odometry>(
      "/sim_rviz_odom", 10);
  }

private:
  void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
  {
    nav_msgs::msg::Odometry position;

    position.header.frame_id = "odom";
    position.child_frame_id = "base_footprint";

    /*==================================================*/

    position.pose.pose.position.x = msg->pose.pose.position.x * 100 + 33;  // [cm]
    position.pose.pose.position.y = msg->pose.pose.position.y * 100 + 50;  // [cm]

    /*==================================================*/

    position.pose.pose.position.z = 0.0;
    position.pose.pose.orientation = msg->pose.pose.orientation;

    publication_->publish(position);
  }

  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publication_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimRvizOdometry>());
  rclcpp::shutdown();
  return 0;
}