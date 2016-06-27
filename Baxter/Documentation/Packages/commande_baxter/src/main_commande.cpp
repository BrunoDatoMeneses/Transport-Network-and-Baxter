/**** Bruno DATO M1 EEA ISTR Université Paul Sabatier Toulouse III 2016 ****/

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

	float compteur = 0 ;

	// Déclaration objet Baxter
	Baxter Baxter(noeud);

	// Déclaration états présents et suivant pour les 2 MEF
	int EP1 , ES1 , EP2 , ES2 ;

	// Fréquence doit être supérieure à 5Hz
  	ros::Rate loop_rate(100); // 100 Hz

	// Initialisation ROBOT //
	Baxter.Init();
	
	// Initialisation MEF //
	EP1 = 1 ; ES1 = 1 ; 
	EP2 = 1 ; ES2 = 1 ; 

	while (ros::ok())
	{

		//std::cout<<EP1<<"	"<<EP2<<std::endl;
		
		// MEF //

		// Bras Droit
		switch (EP1)
    		{
        		case 1: if(compteur > 5) ES1=2; break; 
        		case 2: if(Baxter.Bras_droit.Position_prise_OK()) ES1=3; break;
        		case 3: if(Baxter.Bras_droit.Descente_prise_OK()) ES1=4; break;
        		case 4: if(Baxter.Bras_droit.Pince_fermee_pos()) ES1=5; break;
        		case 5: if(Baxter.Bras_droit.Position_prise_OK() && Baxter.Bras_droit.vitesse_nulle()) ES1=6; break;
        		case 6: if(Baxter.Bras_droit.Position_pose_OK()) ES1=7; break;
        		case 7: if(Baxter.Bras_droit.Descente_pose_OK()) ES1=8; break;
        		case 8: if(Baxter.Bras_droit.Pince_ouverte()) ES1=9; break;
        		case 9: if(Baxter.Bras_droit.Position_pose_OK() && Baxter.Bras_droit.vitesse_nulle()) ES1=1; break;
        		default: break;

    		}

		// Bras Gauche
		switch (EP2)
    		{
        		case 1: if(compteur > 7) ES2=2; break; 
        		case 2: if(Baxter.Bras_gauche.Position_prise_OK()) ES2=3; break;
        		case 3: if(Baxter.Bras_gauche.Descente_prise_OK()) ES2=4; break;
        		case 4: if(Baxter.Bras_gauche.Pince_fermee_pos()) ES2=5; break;
        		case 5: if(Baxter.Bras_gauche.Position_prise_OK() && Baxter.Bras_gauche.vitesse_nulle()) ES2=6; break;
        		case 6: if(Baxter.Bras_gauche.Position_pose_OK()) ES2=7; break;
        		case 7: if(Baxter.Bras_gauche.Descente_pose_OK()) ES2=8; break;
        		case 8: if(Baxter.Bras_gauche.Pince_ouverte()) ES2=9; break;
        		case 9: if(Baxter.Bras_gauche.Position_pose_OK() && Baxter.Bras_gauche.vitesse_nulle()) ES2=1; break;
        		default: break;

    		}
	
		// Etat présent <- Etat suivant
		EP1 = ES1 ;
		EP2 = ES2 ;

		// Actionneurs //

		// Bras droit
		switch (EP1)
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

		// Bras gauche
		switch (EP2)
    		{
        		case 1: Baxter.Bras_gauche.Position_attente(); Baxter.Bras_gauche.Attente_prise(); break;
        		case 2: Baxter.Bras_gauche.Position_prise(); break;
        		case 3: Baxter.Bras_gauche.Descente_prise(); break;
        		case 4: Baxter.Bras_gauche.Prise(); break;
        		case 5: Baxter.Bras_gauche.Position_prise(); break;
        		case 6: Baxter.Bras_gauche.Prise_effectuee(); Baxter.Bras_gauche.Position_pose(); break;
        		case 7: Baxter.Bras_gauche.Descente_pose(); break;
        		case 8: Baxter.Bras_gauche.Pose(); break;
        		case 9: Baxter.Bras_gauche.Position_pose(); break;
        		default: break;

    		}

		// Envoi des commandes vers le robot Baxter
		Baxter.Update();

		ros::spinOnce(); // Lancement des fonctions callback
		loop_rate.sleep(); // Synchronisation avec la fréquence souhaitée

		compteur += 0.01;
	}
	return 0;
}




