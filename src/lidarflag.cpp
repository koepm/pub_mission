#include "mission/mission.hpp"

LidarPublisher::LidarPublisher()
 : Node("lidar_flag")
{
 auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
 lidar_flag_ = this->create_publisher<std_msgs::msg::Bool>("lidar_flag", qos_profile);
 timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&LidarPublisher::publish_lidar_msg, this));
}

void LidarPublisher::publish_lidar_msg()
{
 auto msg = std_msgs::msg::Bool();
 msg.data = true;
 RCLCPP_INFO(this->get_logger(), "Published message: '%s'", std::to_string(msg.data).c_str());
 lidar_flag_->publish(msg);
}

int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv);
 auto node = std::make_shared<LidarPublisher>();
 rclcpp::spin(node);
 rclcpp::shutdown();
 return 0;
}