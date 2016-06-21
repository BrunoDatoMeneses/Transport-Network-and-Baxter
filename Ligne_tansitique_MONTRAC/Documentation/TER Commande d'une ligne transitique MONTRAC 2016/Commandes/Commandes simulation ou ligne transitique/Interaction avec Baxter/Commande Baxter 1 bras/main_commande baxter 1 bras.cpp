/*
 * ************************************* *
 * Copyright 2016, TER Ligne Transitique *
 * All rights reserved.  	         * 
 * ************************************* *
*/


#include "capteurs.h" 
#include "actionneurs.h"
#include "communication_baxter.h" 
#include "commande.h"
#include <ros/ros.h>
#include <unistd.h>

using namespace std;

#define NOMBRE_PLACE 20
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */

int main(int argc, char **argv)
{	

//initialisation du noeud ros et création d'un handle associé au noeud
	ros::init(argc, argv, "commande");	
	ros::NodeHandle noeud;

//création et initialisation des objets Capteur et Actionneurs

	Capteurs Capteurs(noeud);

	Actionneurs Actionneurs(noeud);

	Communication_Baxter Baxter(noeud);

	ros::Rate loop_rate(25); //fréquence de la boucle 


// Déclaration des variables pour la MEF ou le RdP //

	/* Tableau marquage */
	int  M[NOMBRE_PLACE+1];

	/* Capteurs */
	bool PSx[25],DxD[13],DxG[13],CPx[11],CPIx[9];  

	/* Actionneurs */
	bool STx[25],RxD[13],RxG[13],Vx[13],Dx[13],PIx[9]; 

// Initialisation variables //

	Initialisation(PSx,DxD,DxG,CPx,CPIx,STx,RxD,RxG,Vx,Dx,PIx);
	

//////////////////////////////////////////////
//////////// Initialisation RdP //////////////
//////////////////////////////////////////////

			for (int i=0;i<=NOMBRE_PLACE;i++) M[i] = 0 ;

			//Nombre de navettes
			M[4]=2;

			// Disponibilité aiguilllages
	
			
			// Disponibilité bras baxter


			// Pour le positionnement initial navattes sur simulation
			int Deplacement_effectue=0;
	
	

//////////////////////////////////////////////
//////////////////////////////////////////////
//////////////////////////////////////////////

	

	while (ros::ok())
	{
		

		
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		if (Capteurs.SIMULATION) cout <<"~      SIMULATION "<< BOLDGREEN <<"ON"<< RESET <<"    ~"<<endl; 
		else cout <<"~    SIMULATION "<< BOLDRED <<"OFF"<< RESET <<"     ~"<<endl;

		if (Capteurs.LIGNE) cout <<"~  LIGNE TRANSITIQUE "<< BOLDGREEN <<"ON"<< RESET <<" ~"<<endl;
		else cout <<"~ LIGNE TRANSITIQUE "<< BOLDRED <<"OFF"<< RESET <<" ~"<<endl;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;

		

		// Déplacement des navettes si on utilise la simulation
		if(Capteurs.SIMULATION==true && Deplacement_effectue==0)
		{
			//Deplacer_navettes_2(STx,RxD,RxG,Vx,Dx,PIx,Actionneurs,4,4);
			Deplacer_navettes(Actionneurs,STx,RxD,RxG,Vx,Dx,PIx,4);

			Mode_ligne(Actionneurs,STx,RxD,RxG,Vx,Dx,PIx);

			Deplacement_effectue=1;
		}

		// Actualisation des capteurs

		Capteurs.Actualiser(PSx,DxD,DxG,CPx,CPIx);

		Afficher_capteurs(PSx,DxD,DxG,CPx,CPIx);
		Afficher_marquage_RdP(M,NOMBRE_PLACE);

		/////////////////////////////////////////////////
		////////////////////// RdP //////////////////////
		/////////////////////////////////////////////////

		if(M[1]>=1){ if(PSx[1]) {M[1]--; M[2]++;}}			//t1
	
		if(M[2]>=1){ if(DxG[1] && !CPx[2]) {M[2]--; M[3]++;}}		//t2

		if(M[3]>=1){ if(!PSx[1]) {M[3]--; M[4]++;}}			//t3

		if(M[4]>=1){ if(PSx[4]) {M[4]--; M[5]++;}}			//t4

		if(M[5]>=1){ if(DxG[2] && !PSx[20]) {M[5]--; M[6]++;}}		//t5

		if(M[6]>=1){ if(!PSx[4]) {M[6]--; M[7]++;}}			//t6

		if(M[7]>=1){ if(PSx[20]) {M[7]--; M[8]++;}}			//t7

		if(M[8]>=1){ if(DxD[11] && !CPx[9]) {M[8]--; M[9]++;}}		//t8

		if(M[9]>=1){ if(PSx[21] && !PSx[22]) {M[9]--; M[10]++;}}	//t9

		if(M[10]>=1){ if(PSx[22]) {M[10]--; M[11]++; Baxter.Prise_demandee_bras_droit();}}	//t10

		if(M[11]>=1){ if(Baxter.Prise_effectuee_bras_droit() && !PSx[24]) {M[11]--; M[12]++;}}	//t11

		if(M[12]>=1){ if(PSx[24]) {M[12]--; M[13]++;}}			//t12

		if(M[13]>=1){ if(DxD[12] && !PSx[1]) {M[13]--; M[1]++;}}	//t13

               

		
      		// ACTIONNEURS //

		// Déverrouiller
                Dx[1]   = M[2]   ;
		Dx[2]   = M[5]   ;
                Dx[11]  = M[8]   ;
		Dx[12]  = M[13]   ;

		// Verrouiller
		Vx[1]   = M[3]   ;
		Vx[2]   = M[6]   ;
                Vx[11]  = M[9]   ;
                Vx[12]  = M[1]   ;

		// Aiguillage à droite
		RxD[11] = M[8] ;
		RxD[12] = M[13] ;

		// Aiguillage à gauche
                RxG[1]  = M[2] ;
		RxG[2]  = M[5] ;
		
		// Stops		
		STx[1]  = M[3] ;
		STx[4]  = M[6] ;
		STx[6]  = M[7] ;
		STx[20] = M[9] ;
		STx[21] = M[10] ;
		STx[22] = M[12] ;
		STx[24] = M[1] ;
		
		


 		//////////////////////////////////////////////////
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////
		

		Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);

		Baxter.Update();
		Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);


		///////////////////////////////////
		//////////// fin code /////////////
		///////////////////////////////////


		ros::spinOnce(); //permet aux fonction callback de ros dans les objets d'êtres appelées
		loop_rate.sleep(); //permet de synchroniser la boucle while. Il attend le temps qu'il reste pour faire le 25Hz (ou la fréquence indiquée dans le loop_rate)
	}

	return 0;


}
