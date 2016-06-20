#include "ros/ros.h"
#include "scenario1/EntreesSorties.h"
#include "std_msgs/String.h"


void chatterCallback(const scenario1::EntreesSorties msg_entreessorties)
{
  	ROS_INFO("Entrees : %d", msg_entreessorties.entrees);
	ROS_INFO("Sorties : %d", msg_entreessorties.sorties);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "API_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("EntreesSorties", 1000, chatterCallback);

  ros::spin();

  return 0;
}
