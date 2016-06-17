/*
 * ************************************* *
 * Copyright 2016, TER Ligne Transitique *
 * All rights reserved.  	         *
 * ************************************* *
*/


#include "capteurs.h" 
#include "actionneurs.h" 
#include "commande.h"
#include <ros/ros.h>
#include <unistd.h>

using namespace std;

#define NOMBRE_PLACE 34

int main(int argc, char **argv)
{	

//initialisation du noeud ros et création d'un handle associé au noeud
	ros::init(argc, argv, "commande");	
	ros::NodeHandle noeud;

//création et initialisation des objets Capteur et Actionneurs

	Capteurs Capteurs(noeud);

	Actionneurs Actionneurs(noeud);

	ros::Rate loop_rate(20); //fréquence de la boucle (25Hz)


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

	M[8]  = 4;//Nombre de navettes
	M[15] = 1;
	M[16] = 1;
	//M[27] = 2;
	M[33] = 1;
	M[34] = 1;
	
	

//////////////////////////////////////////////
//////////////////////////////////////////////
//////////////////////////////////////////////

	
	int Deplacement_effectue=0;

	while (ros::ok())
	{
		
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		if (Capteurs.SIMULATION) cout <<"~      Simulation ON    ~"<<endl; 
		else cout <<"~    Simulation OFF     ~"<<endl;

		if (Capteurs.LIGNE) cout <<"~  LIGNE TRANSITIQUE ON ~"<<endl;
		else cout <<"~ LIGNE TRANSITIQUE OFF ~"<<endl;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;

		// Déplacement des navettes si on utilise la simulation
		if(Capteurs.SIMULATION==true && Deplacement_effectue==0)
		{
			Deplacer_navettes(Actionneurs,STx,RxD,RxG,Vx,Dx,PIx,5);

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

		//RdP pour l'automates 1 et 2

        	// Implémentation directe


           	//RdP pour l'automates 1 et 2

        	// Implémentation directe


        	if(M[32] && M[16]>=1){ if(PSx[1]) {M[32]--; M[16]--; M[1]++; M[33]++;}}	//t1

		if(M[1]>=1){ if(DxD[1]) {M[1]--;M[2]++;} else if(DxG[1]) { M[1]-- ;M[3]++;}}	//t2 et t3

		if(M[2]>=1){ if(DxG[1] && !CPx[2]) {M[2]--;M[4]++;}}	//t4

		if(M[3]>=1){ if(DxD[1] && !CPx[1]) {M[3]--;M[5]++;}}	//t5

		if(M[4]>=1){ if(!PSx[1]) {M[4]--;M[6]++;}}	//t6

		if(M[5]>=1){ if(!PSx[1]) {M[5]--;M[7]++;}}	//t7

		if(M[6]>=1){ if(PSx[4]) {M[6]--;M[18]++;M[16]++;}}	//t8

		if(M[7]>=1){ if(PSx[2]) {M[7]--;M[8]++;M[16]++;}}	//t9

		if(M[8]>=1 && M[15]>=1){ if(PSx[5]) {M[8]--;M[15]--;M[10]++;}}	//t10

		if(M[18]>=1 && M[15]>=1){ if(1) {M[18]--;M[15]--;M[9]++;}}	//t10'

		if(M[9]>=1){ if(DxG[2] && !PSx[6]) {M[9]--;M[11]++;}}	//t11

		if(M[10]>=1){ if(DxD[2] && !PSx[6]) {M[10]--;M[12]++;}}	//t12

		if(M[11]>=1){ if(!PSx[4]) {M[11]--;M[13]++;}}	//t13

		if(M[12]>=1){ if(!PSx[5]) {M[12]--;M[13]++;}}	//t14

		if(M[13] && M[34] >=1){ if(PSx[20]) {M[13]--; M[34]--; M[19]++; M[15]++;}}	//t15

		if(M[19] >= 1) {if (DxD[11]){M[19]--;M[20]++;} else if(DxG[11]) { M[19]-- ;M[21]++;}} // D11d et D11g

		if(M[20]>=1){ if(DxG[11] && !CPx[10]) {M[20]--;M[22]++;}}

		if(M[22]>=1){ if(!PSx[20]) {M[22]--;M[24]++;}}

		if(M[24]>=1){ if(PSx[23]) {M[24]--;M[26]++;M[34]++;}}

		if(M[26] && M[33] >=1){ if(1) {M[26]--;M[33]--;M[28]++;}}

		if(M[28]>=1){ if(!PSx[1] && DxG[12]) {M[28]--;M[30]++;}}

		if(M[21]>=1){ if(DxD[11] && !CPx[9]) {M[21]--;M[23]++;}}

		if(M[23]>=1){ if(!PSx[20]) {M[23]--;M[25]++;}}

		if(M[25]>=1){ if(PSx[21]) {M[25]--;M[27]++;M[34]++;}}

		if(M[27] && M[33] >=1){ if(PSx[24]) {M[27]--;M[33]--;M[29]++;}}

		if(M[29]>=1){ if(DxD[12] && !PSx[1]) {M[29]--;M[31]++;}}

		if(M[31]>=1){ if(!PSx[24]) {M[31]--;M[32]++;}}

		if(M[30]>=1){ if(!PSx[23]) {M[30]--;M[32]++;}}




                // ACTIONNEURS


		Dx[1]   = M[2]  || M[3] ;
		Dx[2]   = M[9]  || M[10] ;
		Dx[11]  = M[20] || M[21];
		Dx[12]  = M[28] || M[29];

		Vx[1]   = M[4]  || M[5] ;
		Vx[2]   = M[11] || M[12] ;
        	Vx[11]  = M[22] || M[23];
        	Vx[12]  = M[30] || M[31];

		RxD[1]  = M[3] ;
		RxD[2]  = M[10] ;
		RxD[11] = M[21];
		RxD[12] = M[29];
		RxG[1]  = M[2] ;
		RxG[2]  = M[9] ;
		RxG[11] = M[20];
		RxG[12] = M[28];

		STx[1]  = M[4] || M[5] ;
		STx[2]  = M[8] ;
		STx[3]  = M[8] ;
		STx[4]  = M[11] ;
		STx[5]  = M[12] ;
		STx[20] = M[22] || M[23] ;
		STx[21] = M[27] ;
		STx[22] = M[27] ;
		STx[23] = M[30] ;
		STx[24] = M[31] ;
		
		


 		//////////////////////////////////////////////////
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////
		

		Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);

		Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);


		///////////////////////////////////
		//////////// fin code /////////////
		///////////////////////////////////


		ros::spinOnce(); //permet aux fonction callback de ros dans les objets d'êtres appelées
		loop_rate.sleep(); //permet de synchroniser la boucle while. Il attend le temps qu'il reste pour faire le 25Hz (ou la fréquence indiquée dans le loop_rate)
	}

	return 0;


}
