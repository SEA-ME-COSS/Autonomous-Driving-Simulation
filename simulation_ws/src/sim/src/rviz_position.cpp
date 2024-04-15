#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"

using std::placeholders::_1;


class RvizPosition : public rclcpp::Node
{
public:
  RvizPosition()
  : Node("rviz_position")
  {
    subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/piracer/odom", 10, std::bind(&RvizPosition::topic_callback, this, _1));

    publication_ = this->create_publisher<nav_msgs::msg::Odometry>(
      "/rviz_odom", 10);
  }

private:
  void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
  {
    nav_msgs::msg::Odometry position;

    position.header.frame_id = "odom";
    position.child_frame_id = "base_footprint";

    position.pose.pose.position.x = msg->pose.pose.position.x * 100 + 33;  // [cm]
    position.pose.pose.position.y = msg->pose.pose.position.y * 100 + 50;  // [cm]

    // position.pose.pose.position.x = (msg->pose.pose.position.x * 100 + 33) - 9.5 * cos(msg->pose.pose.orientation);  // [cm]
    // position.pose.pose.position.y = (msg->pose.pose.position.y * 100 + 50) - 9.5 * sin(msg->pose.pose.orientation);  // [cm]

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
  rclcpp::spin(std::make_shared<RvizPosition>());
  rclcpp::shutdown();
  return 0;
}