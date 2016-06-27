/**** Bruno DATO M1 EEA ISTR Université Paul Sabatier Toulouse III 2016 ****/

#include <ros/ros.h>
#include "baxter.h"

#include "std_msgs/Bool.h"
#include "baxter_core_msgs/AssemblyState.h"
#include "sensor_msgs/PointCloud.h"

#include "baxter_left_arm.h"
#include "baxter_right_arm.h"

#define PI 3.1416

// Constructeur
Baxter::Baxter(ros::NodeHandle noeud) :

	//Baxter

	Bras_droit(noeud),
	Bras_gauche(noeud),
	
	//Pub
	pub_enable(noeud.advertise<std_msgs::Bool>("/robot/set_super_enable", 1)),

	//Sub
	sub_robot_state(noeud.subscribe("/robot/state", 1, &Baxter::Callback_robot_state,this)),
	sub_sonar(noeud.subscribe("/robot/sonar/head_sonar/state", 1, &Baxter::Callback_sonar,this)),
	sub_halo_led_green(noeud.subscribe("/robot/sonar/head_sonar/lights/green_level", 1, &Baxter::Callback_halo_led_green,this)),
	sub_halo_led_red(noeud.subscribe("/robot/sonar/head_sonar/lights/red_level", 1, &Baxter::Callback_halo_led_red,this))
	

	//Srv

	
	
{
}



// Destructeur
Baxter::~Baxter()
{
}


void Baxter::Init()
{
    	enableRobot.data= 1 ;
	
	Bras_droit.IK(0.3,-0.8,0.5,PI,0,0);
	Bras_gauche.IK(0.3,+0.8,0.5,PI,0,0);
}


// Callbacks

void Baxter::Callback_halo_led_green(const std_msgs::Float32& msg)
{
	halo_led_state_green = msg ;
	//std::cout<<"msg green " <<msg<<std::endl;
}

void Baxter::Callback_halo_led_red(const std_msgs::Float32& msg)
{
	halo_led_state_red = msg ;
	//std::cout<<"msg red " <<msg<<std::endl;
}

void Baxter::Callback_robot_state(const baxter_core_msgs::AssemblyState& msg)
{
	robotSate = msg ;
	//std::cout<<msg<<std::endl;
}

void Baxter::Callback_sonar(const sensor_msgs::PointCloud& msg)
{
	sonar = msg ;
	//std::cout<<sonar<<std::endl;
}



// Envoie des commandes

void Baxter::Update()
{
	pub_enable.publish(enableRobot);

	Bras_droit.Update();
	Bras_gauche.Update();
}



// Commande 










