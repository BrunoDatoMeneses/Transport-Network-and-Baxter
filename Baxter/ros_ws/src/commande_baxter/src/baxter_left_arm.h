#ifndef left_ARM
#define left_ARM

#include <ros/ros.h>


#include "std_msgs/Bool.h"

#include "baxter_core_msgs/JointCommand.h"
#include "baxter_core_msgs/EndEffectorCommand.h"

#include "sensor_msgs/Range.h"
#include "sensor_msgs/JointState.h"
#include "baxter_core_msgs/EndpointState.h"
#include "baxter_core_msgs/EndEffectorState.h"

#include "baxter_core_msgs/SolvePositionIK.h"

class Baxter_left_arm 
{
		// Atributs //

private:

	//Publishers
	ros::Publisher pub_joint_cmd , pub_gripper_cmd, pub_prise_effectuee ;

	//Subscribers
	ros::Subscriber sub_joint_states , sub_endpoint_state , sub_gripper_state , sub_ir_range , sub_prise_demandee ;

	//Client
	ros::ServiceClient client_inverse_kinematics ;

public:

	// Commande	

	baxter_core_msgs::JointCommand msg_JointCommand ;
	baxter_core_msgs::EndEffectorCommand msg_EndEffectorCommand;
	std_msgs::Bool msg_prise_demandee , msg_prise_effectuee;

	// Capteurs

	sensor_msgs::JointState jointState ;
	baxter_core_msgs::EndpointState endpointState ;
	baxter_core_msgs::EndEffectorState endEffectorState;

	
		// Méthodes //

	
	Baxter_left_arm(ros::NodeHandle noeud);
	~Baxter_left_arm();

	// Callbacks

	void Callback_joint_states(const sensor_msgs::JointState& msg);
	void Callback_endpoint_state(const baxter_core_msgs::EndpointState& msg);
	void Callback_gripper_state(const baxter_core_msgs::EndEffectorState& msg);
	void Callback_ir_range(const sensor_msgs::Range& msg);
	void Callback_prise_demandee(const std_msgs::Bool& msg);

	// Commande bras

	void IK(float x, float y, float z, float psy, float teta, float phi);

	void Position(float left_s0, float left_s1, float left_e0, float left_e1, float left_w0, float left_w1, float left_w2);
	void Position_sinu(float position,float compteur);
	void Position(float angle,int num);


	bool Pince_fermee();
	bool Pince_fermee_pos();
	bool Pince_ouverte();

	void Prise();
	void Pose();

	void Position_attente();
	void Position_prise();
	void Position_pose();

	void Descente_prise();
	void Descente_pose();

	void Prise_effectuee();

	bool Prise_demmandee();
	bool vitesse_nulle();
	bool Position(float x, float y, float z);

	bool Position_prise_OK();
	bool Position_pose_OK();
	bool Descente_pose_OK();
	bool Descente_prise_OK();

	


	// Commande pince

	void Grip();
	void Release();

	// Envoi des commandes

	void Update();
};


#endif
