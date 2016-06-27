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

	// Déclaration de l'objet Baxter
	Baxter Baxter(nd);

	float compteur = 0 ;

	// Fréquence doit être supérieure à 5Hz
  	ros::Rate loop_rate(700);

	// Initialisation ROBOT //
	Baxter.Init();
	
	while (ros::ok())
	{
		// Vague pour les bras gauche et droit en déphasage de PI
		Baxter.Bras_droit.Position_sinu(0.5,compteur+PI);
		Baxter.Bras_gauche.Position_sinu(0.5,compteur);

		// Envoi des positions vers Baxter
		Baxter.Update();

		compteur += 0.003 ;

		ros::spinOnce(); // Lancement des fonctions callback
		loop_rate.sleep(); // synchronisation avec la fréquence souhaitée

	}
	return 0;
}




