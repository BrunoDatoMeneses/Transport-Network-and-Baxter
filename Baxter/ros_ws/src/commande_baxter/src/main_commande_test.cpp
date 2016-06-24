/*
 * ************************************* *
 * Copyright 2016, STAGE BAXTER          *
 * All rights reserved.  	         *
 * ************************************* *
*/

#include "baxter.h"
#include "baxter_left_arm.h" 
#include "baxter_right_arm.h" 
#include <ros/ros.h>

#include <iostream> 
#include <unistd.h>

#define PI 3.1416

using namespace std;


int main(int argc, char **argv)
{	

//initialisation du noeud ros et création d'un handle associé au noeud
	ros::init(argc, argv, "commande_baxter_test");	   
	ros::NodeHandle nd;

	Baxter Baxter(nd);

	float compteur = 0 ;

	// Fréquence doit être supérieure à 5Hz
  	ros::Rate loop_rate(200);

	// Initialisation ROBOT //

	Baxter.Init();
	

	while (ros::ok())
	{

		Baxter.Bras_droit.Position_sinu(0.5,compteur);
		Baxter.Bras_gauche.Position_sinu(0.5,compteur);

		Baxter.Update();

		compteur += 0.01 ;

		ros::spinOnce(); 
		loop_rate.sleep(); 

	}
	return 0;
}




