/*
 * ************************************* *
 * Copyright 2016, STAGE BAXTETR         *
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
	ros::init(argc, argv, "commande_baxter");	
	ros::NodeHandle noeud;

	Baxter Baxter(noeud);

	float compteur = 0 ;
	int EP , ES ;

	// Fréquence doit être supérieure à 5Hz
  	ros::Rate loop_rate(100);

	// Initialisation ROBOT //

	Baxter.Init();
	
	// Initialisation MEF //

	EP = 1 ; ES = 1 ; 

	while (ros::ok())
	{

		//std::cout<<EP<<<<std::endl;
		
		switch (EP)
    		{
        		case 1: if(compteur>5) ES=2; break; 
        		case 2: if(Baxter.Bras_droit.Position_prise_OK()) ES=3; break;
        		case 3: if(Baxter.Bras_droit.Descente_prise_OK()) ES=4; break;
        		case 4: if(Baxter.Bras_droit.Pince_fermee_pos()) ES=5; break;
        		case 5: if(Baxter.Bras_droit.Position_prise_OK() && Baxter.Bras_droit.vitesse_nulle()) ES=6; break;
        		case 6: if(Baxter.Bras_droit.Position_pose_OK()) ES=7; break;
        		case 7: if(Baxter.Bras_droit.Descente_pose_OK()) ES=8; break;
        		case 8: if(Baxter.Bras_droit.Pince_ouverte()) ES=9; break;
        		case 9: if(Baxter.Bras_droit.Position_pose_OK() && Baxter.Bras_droit.vitesse_nulle()) ES=1; break;
        		default: break;

    		}
	
		EP = ES ;

		switch (EP)
    		{
        		case 1: Baxter.Bras_droit.Position_attente(); Baxter.Bras_droit.Attente_prise(); break;
        		case 2: Baxter.Bras_droit.Position_prise(); break;
        		case 3: Baxter.Bras_droit.Descente_prise(); break;
        		case 4: Baxter.Bras_droit.Prise(); break;
        		case 5: Baxter.Bras_droit.Position_prise(); break;
        		case 6: Baxter.Bras_droit.Prise_effectuee(); Baxter.Bras_droit.Position_pose(); break;
        		case 7: Baxter.Bras_droit.Descente_pose(); break;
        		case 8: Baxter.Bras_droit.Pose(); break;
        		case 9: Baxter.Bras_droit.Position_pose(); break;
        		default: break;

    		}


		
		Baxter.Update();

		compteur += 0.01 ;

		ros::spinOnce(); 
		loop_rate.sleep(); 

	}
	return 0;
}




