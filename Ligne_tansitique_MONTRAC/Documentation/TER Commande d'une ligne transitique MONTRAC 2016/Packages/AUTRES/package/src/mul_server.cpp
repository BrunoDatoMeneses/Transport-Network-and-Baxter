#include "ros/ros.h"
#include "package/Mul.h"

bool add(package::Mul::Request  &req,
         package::Mul::Response &res)
{
  res.mul = req.a * req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.mul);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "mul_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("mul", add);
  ROS_INFO("Ready to mul two ints.");
  ros::spin();

  return 0;
}
