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

#define NOMBRE_PLACE 66

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

	M[8]  = 6;//Nombre de navettes
	M[15] = 1;
	M[16] = 1;
	//M[27] = 2;

	M[33] = 1;
	M[34] = 1;

	M[49] = 1;
	M[59] = 1;
	M[66] = 1;
        M[77] = 1 ;
	M[78] = 1 ;
	M[82] = 1 ;
	M[94] = 1 ;
	M[95] = 1 ;
	M[86] = 1 ;



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


               if(M[32]){ if(PSx[1]) {M[32]--; M[16]--; M[1]++; M[33]++;}}	//t1


		if(M[1]>=1 && M[16]>=1){ if(DxD[1]) {M[1]--;M[2]++;} else if(DxG[1]) { M[1]-- ;M[3]++;}}	//t2 et t3

		if(M[2]>=1){ if(DxG[1] && !CPx[2]) {M[2]--;M[4]++;}}	//t4

		if(M[3]>=1){ if(DxD[1] && !CPx[1]) {M[3]--;M[5]++;}}	//t5

		if(M[4]>=1){ if(!PSx[1]) {M[4]--;M[6]++;}}	//t6

		if(M[5]>=1){ if(!PSx[1]) {M[5]--;M[7]++;}}	//t7

		if(M[6]>=1){ if(PSx[4]) {M[6]--;M[18]++;M[16]++;}}	//t8

		if(M[7]>=1){ if(PSx[2]) {M[7]--;M[8]++;M[16]++;}}	//t9

		if(M[8]>=1 && M[15]>=1){ if(PSx[5]) {M[8]--;M[15]--;M[10]++;}}	//t10

		if(M[13]>=1){ if(PSx[20]) {M[13]--;M[15]++;M[19]++;}}	//fusion PS20

		if(M[18]>=1 && M[15]>=1){ if(1) {M[18]--;M[15]--;M[9]++;}}	//t10'

		if(M[9]>=1){ if(DxG[2] && !PSx[6]) {M[9]--;M[11]++;}}	//t11

		if(M[10]>=1){ if(DxD[2] && !PSx[6]) {M[10]--;M[12]++;}}	//t12

		if(M[11]>=1){ if(!PSx[4]) {M[11]--;M[13]++;}}	//t13

		if(M[12]>=1){ if(!PSx[5]) {M[12]--;M[13]++;}}	//t14

		if(M[13]){ if(PSx[20]) {M[13]--; M[19]++; M[15]++;}}	//t15

		if(M[19] >= 1 && M[34] >= 1) {if (DxD[11]){M[19]--;M[34]--;M[20]++;} else if(DxG[11]) { M[19]--;M[34]--;M[21]++;}}//D11d et D11g

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

		if(M[32]>=1){ if(PSx[1]) {M[32]--;M[33]++;M[1]++;}} //fusion PS1

//la partie à droite en bas

                if(M[64]){ if(PSx[13]) {M[64]--; M[50]--; M[35]++; M[65]++;}}

                if(M[35]>=1 && M[50]){ if(DxD[7]) {M[35]--;M[50]--;M[36]++;} else if(DxG[7]) { M[35]--;M[50]--;M[37]++;}}

		if(M[36]>=1){ if(DxG[7] && !CPx[7]) {M[35]--;M[38]++;}}

		if(M[37]>=1){ if(DxD[7] && !CPx[6]) {M[37]--;M[39]++;}}

		if(M[38]>=1){ if(!PSx[13]) {M[38]--;M[40]++;}}

		if(M[39]>=1){ if(!PSx[13]) {M[39]--;M[41]++;}}

		if(M[40]>=1){ if(PSx[16]) {M[40]--;M[42]++;M[50]++;}}

		if(M[41]>=1){ if(PSx[14]) {M[41]--;M[43]++;M[50]++;}}

		if(M[43]>=1 && M[49]>=1){ if(PSx[17]) {M[43]--;M[49]--;M[45]++;}}

		if(M[42]>=1 && M[49]>=1){ if(1) {M[42]--;M[49]--;M[44]++;}}

		if(M[44]>=1){ if(DxG[8] && !PSx[18]) {M[44]--;M[46]++;}}

		if(M[45]>=1){ if(DxD[8] && !PSx[18]) {M[45]--;M[47]++;}}

		if(M[46]>=1){ if(!PSx[16]) {M[46]--;M[48]++;}}

		if(M[47]>=1){ if(!PSx[17]) {M[47]--;M[48]++;}}

//la partie à droite en haut

		if(M[48]){ if(PSx[18]) {M[48]--; M[70]++; M[49]++;}}

		if(M[51] >= 1) {if (DxD[4]){M[51]--;M[52]++;} else if(DxG[4]) { M[51]-- ;M[53]++;}}

		if(M[52]>=1){ if(DxG[4] && !CPx[5]) {M[52]--;M[54]++;}}

		if(M[54]>=1){ if(!PSx[8]) {M[54]--;M[56]++;}}

		if(M[56]>=1){ if(PSx[11]) {M[56]--;M[56]++;M[66]++;}}

		if(M[58] && M[65] >=1){ if(1) {M[58]--;M[65]--;M[60]++;}}

		if(M[60]>=1){ if(!PSx[13] && DxG[6]) {M[60]--;M[62]++;}}

		if(M[53]>=1){ if(DxD[4] && !CPx[4]) {M[53]--;M[55]++;}}

		if(M[55]>=1){ if(!PSx[8]) {M[55]--;M[57]++;}}

		if(M[57]>=1){ if(PSx[9]) {M[57]--;M[59]++;M[66]++;}}

		if(M[59] && M[65] >=1){ if(PSx[12]) {M[59]--;M[65]--;M[61]++;}}

		if(M[61]>=1){ if(DxD[6] && !PSx[13]) {M[61]--;M[63]++;}}

		if(M[63]>=1){ if(!PSx[12]) {M[63]--;M[64]++;}}

		if(M[62]>=1){ if(!PSx[11]) {M[62]--;M[64]++;}}

//Début Partie milieu 

           	if(M[70]>=1 && M[78]>=1 && M[77]>=1){ if(DxG[9]) {M[70]--;M[77]--;M[78]--;M[71]++;} else if (DxD[9]) {M[70]--;M[77]--;M[78]--;M[74]++;}}	

		if(M[74]>=1){ if(DxG[9] && DxG[4] && !PSx[8]) {M[74]--;M[75]++;} }	

		if(M[75]>=1){ if(!PSx[18]) {M[75]--;M[76]++;}}	

		if(M[76]>=1 && M[85]>=1){ if(PSx[8]) {M[76]--;M[85]--; M[77]++;M[78]++;M[77]++;}}	

		if(M[71]>=1){ if(DxD[9] && !PSx[8] ) {M[71]--;M[72]++;}}	

		if(M[72]>=1){ if(!PSx[18]) {M[72]--;M[73]++;}}	

		if(M[73]>=1){ if(PSx[19]) {M[73]--;M[78]++;M[79]--;}}	


               if(M[87]>=1 && M[95]>=1 && M[94]>=1){ if(DxD[3]) {M[87]--;M[95]--;M[94]--;M[91]++;} else if (DxG[3]) {M[87]--;M[95]--;M[94]--;M[88]++;}}	

		if(M[91]>=1){ if(DxG[3] && DxG[10] && !PSx[20]) {M[91]--;M[92]++;} }	

		if(M[92]>=1){ if(PSx[6]) {M[92]--;M[93]++;}}	

		if(M[93]>=1){ if(PSx[20]) {M[93]--;M[94]++;M[95]++;}}	

		if(M[88]>=1){ if(DxD[3] && !PSx[3] ) {M[88]--;M[89]++;}}

		if(M[89]>=1){ if(!PSx[6]) {M[89]--;M[90]++;}}	

		if(M[90]>=1){ if(PSx[7]) {M[90]--;M[95]++;M[83]++;}}

		if(M[79]>=1){ if(DxD[10] && !PSx[20]) {M[79]--;M[80]++;}}	

		if(M[80]>=1){ if(!PSx[19]) {M[80]--;M[81]++;}}		

		if(M[81]>=1){ if(PSx[20]) {M[81]--;M[94]++;}}	

		if(M[94]>=1){ if(PSx[19]) {M[94]--;M[79]++;}}		

		if(M[83]>=1){ if(DxD[4] && !PSx[8]) {M[83]--;M[84]++;}}	

		if(M[84]>=1){ if(!PSx[7]) {M[84]--;M[85]++;}}	

		if(M[85]>=1){ if(PSx[8]) {M[85]--;M[77]++;M[51]++;}}	

		if(M[77]>=1){ if(PSx[7]) {M[77]--;M[83]++;}}	
//Fin Partie milieu       	




                // ACTIONNEURS

                Dx[1]   = M[2]   || M[3] ;
		Dx[2]   = M[9]   || M[10] ;
                Dx[3]   = M[88]  || M[91] ;
		Dx[4]   = M[83]  || M[74] || M[52] || M[53];
		Dx[6]   = M[60]  || M[61];
                Dx[7]   = M[36]  || M[37] ;
		Dx[8]   = M[44]  || M[45] ;
		Dx[9]   = M[74]  || M[71] ;
		Dx[10]  = M[79] || M[91];
                Dx[11]  = M[20] || M[21];
		Dx[12]  = M[28] || M[29];


		Vx[1]   = M[4]  || M[5] ;
		Vx[2]   = M[11] || M[12] ;
		Vx[3]   = M[92]  || M[89] ;
		Vx[4]   = M[84]  || M[75] || M[54] || M[55];
                Vx[6]   = M[62] || M[63];
                Vx[7]   = M[38] || M[39] ;
		Vx[8]   = M[46] || M[47] ;
		Vx[9]   = M[72]  || M[75] ;
		Vx[10]  = M[80] || M[92];
                Vx[11]  = M[22] || M[23];
                Vx[12]  = M[30] || M[31];

                RxD[1]  = M[3] || M[2]  ;
		RxD[2]  = M[10] || M[9] ;
		RxD[3]  = M[88] ;
		RxD[4]  = M[83] || M[74] || M[53];
		RxD[6]  = M[61] ;
		RxD[7]  = M[37] ;
		RxD[8]  = M[45] ;
		RxD[9]  = M[71] ;
		RxD[10] = M[79] ;
		RxD[11] = M[21] ;
		RxD[12] = M[29] ;

		
		RxG[3]  = M[91] ;
		RxG[4]  = M[74] ||M[52] ;
		RxG[6]  = M[60] ;
		RxG[7]  = M[36] ;
		RxG[8]  = M[44] ;
		RxG[9]  = M[74]  ;
		RxG[10] = M[91] ;
		RxG[11] = M[20] ;
		RxG[12] = M[28] ;
		
		STx[1]  = M[4] || M[5] ;
		STx[2]  = M[8] ;
		STx[3]  = M[8] ;
		STx[4]  = M[11] ;
		STx[5]  = M[12] ;
		STx[6]  = M[89] || M[92] ; 
		STx[7]  = M[84] ;
                STx[8]  = M[54] || M[55] ;
		STx[9]  = M[59] ;
		STx[10] = M[59] ;
	        STx[11] = M[62] ;
		STx[12] = M[63] ;
		STx[13] = M[38] || M[39] ;
		STx[14] = M[43] ;
		STx[15] = M[43] ;
		STx[16] = M[46] ;
		STx[17] = M[47] ;
		STx[18] = M[48] ; 
		STx[18] = M[75] || M[72] ;
		STx[19] = M[80] ; 
		STx[20] = M[22] || M[23] ;
		STx[21] = M[27] ;
		STx[22] = M[27] ;
		STx[23] = M[30] ;
		STx[24] = M[31] ;
           

                STx[20] = M[14] || t; 

		if (c >= 900) STx[24] = M[17] ;
		else STx[24] = false;

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
