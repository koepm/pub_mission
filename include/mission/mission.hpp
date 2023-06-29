#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"
#include "std_msgs/msg/int16.hpp"

class LidarPublisher : public rclcpp::Node
{
public:
    LidarPublisher();

private:
    void publish_lidar_msg();

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr lidar_flag_;
    size_t count_;
};


class MissionPublisher : public rclcpp::Node
{
public:
    MissionPublisher();

private:
    void publish_mission_msg();

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr mission_flag_;
    size_t count_;
};