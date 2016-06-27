/**** Bruno DATO M1 EEA ISTR Université Paul Sabatier Toulouse III 2016 ****/

#ifndef right_ARM
#define right_ARM

#include <ros/ros.h>

#include "std_msgs/Bool.h"

#include "baxter_core_msgs/JointCommand.h"
#include "sensor_msgs/JointState.h"
#include "baxter_core_msgs/SolvePositionIK.h"

class Baxter_right_arm 
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

	
	Baxter_right_arm(ros::NodeHandle noeud);
	~Baxter_right_arm();

	// Callbacks

	void Callback_joint_states(const sensor_msgs::JointState& msg);

	// Commande bras


	void Position(float right_s0, float right_s1, float right_e0, float right_e1, float right_w0, float right_w1, float right_w2);
	void Position_sinu(float position,float compteur);
	void Position(float angle,int num);

	void IK(float x, float y, float z, float psy, float teta, float phi);


	// Envoi des commandes

	void Update();
};


#endif
