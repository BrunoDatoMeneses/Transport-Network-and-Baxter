/**** Bruno DATO M1 EEA ISTR Université Paul Sabatier Toulouse III 2016 ****/

#ifndef left_ARM
#define left_ARM

#include <ros/ros.h>

#include "std_msgs/Bool.h"

#include "baxter_core_msgs/JointCommand.h"
#include "sensor_msgs/JointState.h"
#include "baxter_core_msgs/SolvePositionIK.h"

class Baxter_left_arm 
{
		// Atributs //

private:

	//Publishers
	ros::Publisher pub_joint_cmd  ;

	//Subscribers
	ros::Subscriber sub_joint_states ;

	//Client
	ros::ServiceClient client_inverse_kinematics ;


public:

	// Commande	

	baxter_core_msgs::JointCommand msg_JointCommand ;
	

	// Capteurs

	sensor_msgs::JointState jointState ;


	
		// Méthodes //

	
	Baxter_left_arm(ros::NodeHandle noeud);
	~Baxter_left_arm();

	// Callbacks

	void Callback_joint_states(const sensor_msgs::JointState& msg);

	// Commande bras


	void Position(float left_s0, float left_s1, float left_e0, float left_e1, float left_w0, float left_w1, float left_w2);
	void Position_sinu(float position,float compteur);
	void Position(float angle,int num);

	void IK(float x, float y, float z, float psy, float teta, float phi);


	// Envoi des commandes

	void Update();
};


#endif
