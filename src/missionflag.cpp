#include "mission/mission.hpp"

MissionPublisher::MissionPublisher()
 : Node("mission_flag")
{
 auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
 mission_flag_ = this->create_publisher<std_msgs::msg::Int16>("mission_flag", qos_profile);
 timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&MissionPublisher::publish_mission_msg, this));
}

void MissionPublisher::publish_mission_msg()
{
 auto msg = std_msgs::msg::Int16();
 msg.data = 10;
 RCLCPP_INFO(this->get_logger(), "Published message: '%s'", std::to_string(msg.data).c_str());
 mission_flag_->publish(msg);
}

int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv);
 auto node = std::make_shared<MissionPublisher>();
 rclcpp::spin(node);
 rclcpp::shutdown();
 return 0;
}