/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/


using namespace std;

#include "vrepController.h"
#include "UI.h"
#include "inOutController.h"

#include <ros/ros.h>

int main(int argc, char **argv)
{
			//Initialisation du noeud ROS
			ros::init(argc, argv, "commande_locale");
			ros::NodeHandle nh;

			// VREP CONTROLLER
			vrepController VREPController;
			VREPController.init(nh);

			// USER INTERFACE
			UI userInterface(&VREPController);
			userInterface.init(nh);

			// IN & OUT CONTROLLER
			inOutController IOController(&userInterface);
			IOController.init(nh);

			// Ajout des Shuttle dans la simulation
			for(int i=1;i<=argc-1;i++) VREPController.loadModel(argv[i][0]);

			// Demarrage de la simu pour avoir la premiere image
			VREPController.play();

			// Pause pour laisser à l'utilisateur le soin de lancer la simu avec le boutton Play
			VREPController.pause();

			while (ros::ok()) // Tant que ROS est actif,
			{
				ros::spinOnce(); // on lance les callback correspondant aux messages entrants.
			}				
				
			userInterface.close(); // Si Ctrl+C -> On ferme la fenetre de l'UI et on quitte la simulation
			VREPController.close();
			return 0;
}
