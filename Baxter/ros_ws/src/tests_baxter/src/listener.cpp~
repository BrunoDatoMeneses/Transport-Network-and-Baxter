#include "ros/ros.h"

#include "std_msgs/String.h"
#include "baxter_core_msgs/AssemblyState.h"
#include "sensor_msgs/JointState.h"
#include "baxter_core_msgs/EndpointState.h"
#include "baxter_core_msgs/EndEffectorState.h"


#include <iostream> 
using namespace std;




void Callback_joint_states(const sensor_msgs::JointState& msg)
{
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout<<"~~~ Positions des angles ~~~"<<std::endl;
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl<<std::endl;
	std::cout<<msg<<std::endl<<std::endl;
}


void Callback_endpoint_state_left(const baxter_core_msgs::EndpointState& msg)
{
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout<<"~~~ Position cartésienne et orientation bras gauche ~~~"<<std::endl;
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl<<std::endl;
	std::cout<<msg<<std::endl<<std::endl;
}

void Callback_endpoint_state_right(const baxter_core_msgs::EndpointState& msg)
{
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout<<"~~~ Position cartésienne et orientation bras droit ~~~"<<std::endl;
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl<<std::endl;
	std::cout<<msg<<std::endl<<std::endl;
}


void Callback_gripper_state_right(const baxter_core_msgs::EndEffectorState& msg)
{
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout<<"~~~ Etat pince droite ~~~"<<std::endl;
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl<<std::endl;
	std::cout<<msg<<std::endl<<std::endl;
}

void Callback_gripper_state_left(const baxter_core_msgs::EndEffectorState& msg)
{
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout<<"~~~ Etat pince gauche ~~~"<<std::endl;
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl<<std::endl;
	std::cout<<msg<<std::endl<<std::endl;
}





int main(int argc, char **argv)
{
  
  	ros::init(argc, argv, "listener");
  	ros::NodeHandle n;


	// Subscribers

	ros::Subscriber sub_joint_states = n.subscribe("/robot/joint_states", 1, Callback_joint_states);

	ros::Subscriber sub_endpoint_state_left = n.subscribe("/robot/limb/left/endpoint_state", 1, Callback_endpoint_state_left);

	ros::Subscriber sub_endpoint_state_right = n.subscribe("/robot/limb/right/endpoint_state", 1, Callback_endpoint_state_right);

	ros::Subscriber sub_gripper_state_right = n.subscribe("/robot/end_effector/right_gripper/state", 1, Callback_gripper_state_right);

	ros::Subscriber sub_gripper_state_left = n.subscribe("/robot/end_effector/left_gripper/state", 1, Callback_gripper_state_left);
	
	
	ros::Rate loop_rate(1); //1 Hz

	while(ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}
  return 0;
}

