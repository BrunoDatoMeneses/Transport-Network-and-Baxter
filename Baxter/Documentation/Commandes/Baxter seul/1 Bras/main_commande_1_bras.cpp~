/*
 * ************************************* *
 * Copyright 2016, STAGE BAXTETR         *
 * All rights reserved.  	         *
 * ************************************* *
*/

#include "baxter.h"
#include "baxter_left_arm.h" 
#include "baxter_right_arm.h" 
#include "commande.h"
#include <ros/ros.h>

#include <iostream> 
#include <unistd.h>

#define PI 3.1416

using namespace std;


int main(int argc, char **argv)
{	

//initialisation du noeud ros et création d'un handle associé au noeud
	ros::init(argc, argv, "commande");	
	ros::NodeHandle noeud;

	Baxter Baxter(noeud);
	Baxter_left_arm Bras_gauche(noeud);
	Baxter_right_arm Bras_droit(noeud);

	float compteur = 0 ;
	int EP , ES ;

	// Fréquence doit être supérieure à 5Hz
  	ros::Rate loop_rate(50);


	// Initialisation ROBOT //

	
	Position_attente(&Bras_gauche,&Bras_droit);


	// Initialisation MEF //

	EP = 1 ; ES = 1 ;

	
	
	

	while (ros::ok())
	{
		std::cout<<EP<<"	"<<compteur<<"		"<<vitesse_nulle(Bras_gauche,Bras_droit)<<"	"<<Bras_droit.endEffectorState.position<<std::endl;
		//Descente_prise(&Bras_droit);
		
		switch (EP)

    		{
        		case 1: if(compteur > 3) ES=2; break; // Simulation événement
        		case 2: if(vitesse_nulle(Bras_gauche,Bras_droit)) ES=3; break;
        		case 3: if(vitesse_nulle(Bras_gauche,Bras_droit)) ES=4; break;
        		case 4: if(vitesse_nulle(Bras_gauche,Bras_droit) && Pince_fermee_pos(Bras_droit)) ES=5; break;
        		case 5: if(vitesse_nulle(Bras_gauche,Bras_droit)) ES=6; break;
        		case 6: if(vitesse_nulle(Bras_gauche,Bras_droit)) ES=7; break;
        		case 7: if(vitesse_nulle(Bras_gauche,Bras_droit)) ES=8; break;
        		case 8: if(vitesse_nulle(Bras_gauche,Bras_droit) && Pince_ouverte(Bras_droit)) ES=9; break;
        		case 9: if(vitesse_nulle(Bras_gauche,Bras_droit)) ES=1; break;
        		default: break;

    		}
	
		EP = ES ;

		switch (EP)

    		{
        		case 1: Position_attente(&Bras_gauche,&Bras_droit); break;
        		case 2: Position_prise(&Bras_droit); break;
        		case 3: Descente_prise(&Bras_droit); break;
        		case 4: Prise(&Bras_droit); break;
        		case 5: Position_prise(&Bras_droit); break;
        		case 6: Position_pose(&Bras_droit); break;
        		case 7: Descente_pose(&Bras_droit); break;
        		case 8: Pose(&Bras_droit); break;
        		case 9: Position_pose(&Bras_droit); break;
        		default: break;

    		}

		Baxter.Update();
		Bras_gauche.Update();
		Bras_droit.Update();

		compteur += 0.05 ;

		ros::spinOnce(); 
		loop_rate.sleep(); 

	}
	return 0;
}




