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

#define NOMBRE_PLACE 100
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

	ros::Rate loop_rate(30); //fréquence de la boucle 


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

	//Nombre de navettes (6)
	M[48]=3; 
	M[88]=3;

	// Disponibilité aiguilllages
	M[1]  = 1;
	M[2]  = 1;
	M[3]  = 1;
	M[4]  = 1;
	M[5]  = 1;
	M[6]  = 1; 
	M[7]  = 1;
	M[8]  = 1;
	M[9]  = 1;
	M[10] = 1;
	M[11] = 1;
	M[12] = 1;
	
			
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
			// Déplacement devant 2 stops différents pour initialisation
			Deplacer_navettes_2(STx,RxD,RxG,Vx,Dx,PIx,Actionneurs,12,24);

			//Mode_ligne(Actionneurs,STx,RxD,RxG,Vx,Dx,PIx);

			Deplacement_effectue=1;
		}

		// Actualisation des capteurs

		Capteurs.Actualiser(PSx,DxD,DxG,CPx,CPIx);
		Afficher_capteurs(PSx,DxD,DxG,CPx,CPIx);
		Afficher_marquage_RdP(M,NOMBRE_PLACE);

		/////////////////////////////////////////////////
		////////////////////// RdP //////////////////////
		/////////////////////////////////////////////////

		if(M[93]>=1){ if(PSx[1]) {M[93]--; M[20]++; }}					//I

		// A1 et A2

                if(M[1]>=1 && M[20]>=1){ 	if(DxD[1]) {M[20]--;M[1]--;M[21]++;} 		//t1
                                   		else if(DxG[1]) {M[20]--;M[1]--;M[22]++;}}	//t2

		if(M[21]>=1){ if(DxG[1] && !CPx[2]) {M[21]--;M[23]++;}}				//t3

		if(M[22]>=1){ if(DxD[1] && !CPx[1]) {M[22]--;M[24]++;}}				//t4

		if(M[23]>=1){ if(!PSx[1]) {M[23]--;M[25]++;}}					//t5

		if(M[24]>=1){ if(!PSx[1]) {M[24]--;M[26]++;}}					//t6

		if(M[25]>=1){ if(PSx[4]) {M[25]--;M[27]++;M[1]++;M[12]++;}}			//t7

		if(M[26]>=1){ if(PSx[2]) {M[26]--;M[28]++;M[1]++;M[12]++;}}			//t8

		if(M[27]>=1 && M[2]>=1){ if(1) {M[27]--;M[2]--;M[29]++;}}			//t9

		if(M[28]>=1 && M[2]>=1){ if(PSx[5]) {M[28]--;M[2]--;M[30]++;}}			//t10
	
		if(M[29]>=1){ if(DxG[2] && !PSx[6]) {M[29]--;M[31]++;}}				//t11

		if(M[30]>=1){ if(DxD[2] && !PSx[6]) {M[30]--;M[32]++;}}				//t12

		if(M[31]>=1){ if(!PSx[4]) {M[31]--;M[33]++;}}					//t13

		if(M[32]>=1){ if(!PSx[5]) {M[32]--;M[33]++;}}					//t14

		//

		if(M[33]>=1){ if(PSx[6]) {M[33]--;M[94]++ ;}}					//II  
 
                // A3 et A10


		 if(M[94]>=1 && M[3]>=1 && M[10]>=1){if(DxD[3]){M[10]--;M[94]--; M[3]--;M[54]++;}} 	//t81

		 if(M[94]>=1 && M[3]>=1 ){if (DxG[3]){M[94]--;M[3]--;M[55]++;}} 			//t82 			

		 if(M[54]>=1){if(DxG[3] && !PSx[20]){M[54]--;M[56]++;}} 			//t83   

		 if(M[55]>=1){if(DxD[3] && !CPx[3]){M[55]--;M[57]++;}} 				//t84   

		 if(M[56]>=1){if(!PSx[6]){M[56]--;M[58]++;}} 					//t85  

		 if(M[57]>=1){if(!PSx[6]){M[57]--;M[59]++;}} 					//t86 

		//      

		  
				
		 if(M[59]>=1 && M[4]>=1){if(PSx[7]){M[59]--;M[4]--;M[3]++;M[34]++;M[2]++;}} 	//III    

		//  A4        

		 if(M[34]>=1){if(!PSx[8] && DxD[4]){M[34]--;M[35]++;}} 				//87 

		 if(M[35]>=1){if(!PSx[7]){M[35]--;M[36]++;}} 					//t88 

		// 

		 if(M[36]>=1){if(PSx[8]){M[36]--;M[40]++;}} 					//IV
		
		 if(M[78]>=1){if(PSx[8]){M[78]--;M[40]++;M[9]++;M[8]++;}} 			//IV'  	

		// A5 et A6

               	if(M[40]>=1 && M[5]>=1){ 	if(DxD[5]) {M[40]--;M[5]--;M[41]++;} 		//t21
                                      		else if(DxG[5]) {M[40]--;M[5]--;M[42]++;}}	//t22

		if(M[41]>=1){ if(DxG[5] && !CPx[5]) {M[41]--;M[43]++;}}				//t23

		if(M[42]>=1){ if(DxD[5] && !CPx[4]) {M[42]--;M[44]++;}}				//t24

		if(M[43]>=1){ if(!PSx[8]) {M[43]--;M[45]++;}}					//t25

		if(M[44]>=1){ if(!PSx[8]) {M[44]--;M[46]++;}}					//t26

		if(M[45]>=1){ if(PSx[11]) {M[45]--;M[47]++;M[5]++;M[4]++;}}			//t27

		if(M[46]>=1){ if(PSx[9]) {M[46]--;M[48]++;M[5]++;M[4]++;}}			//t28

	        if(M[47]>=1 && M[6]>=1){ if(1) {M[47]--;M[6]--;M[49]++;}}			//t29

		if(M[48]>=1 && M[6]>=1){ if(PSx[12]) {M[48]--;M[6]--;M[50]++;}}			//t30

		if(M[49]>=1){ if(DxG[6] && !PSx[13]) {M[49]--;M[51]++;}}			//t31

		if(M[50]>=1){ if(DxD[6] && !PSx[13]) {M[50]--;M[52]++;}}			//t32

		if(M[51]>=1){ if(!PSx[11]) {M[51]--;M[53]++;}}					//t33

		if(M[52]>=1){ if(!PSx[12]) {M[52]--;M[53]++;}}					//t34

		//

		if(M[53]>=1){ if(PSx[13]) {M[53]--; M[60]++;}}					//V 

             	//A7 et A8

                if(M[7]>=1 && M[60]>=1){	if(DxD[7]) {M[60]--;M[7]--;M[61]++;} 		//t41
                                     		else if(DxG[7]) {M[60]--;M[7]--;M[62]++;}} 	//t42

		if(M[61]>=1){ if(DxG[7] && !CPx[7]) {M[61]--;M[63]++;}} 			//t43

		if(M[62]>=1){ if(DxD[7] && !CPx[6]) {M[62]--;M[64]++;}} 			//t44

		if(M[63]>=1){ if(!PSx[13]) {M[63]--;M[65]++;}}	 				//t45

		if(M[64]>=1){ if(!PSx[13]) {M[64]--;M[66]++;}} 					//t46

		if(M[65]>=1){ if(PSx[16]) {M[65]--;M[67]++;M[6]++;M[7]++;}} 			//t47

		if(M[66]>=1){ if(PSx[14]) {M[66]--;M[68]++;M[6]++;M[7]++;}}  			//t48

		if(M[67]>=1 && M[8]>=1){ if(1) {M[67]--;M[8]--;M[69]++;}}			//t49

		if(M[68]>=1 && M[8]>=1){ if(PSx[17]) {M[68]--;M[8]--;M[70]++;}} 		//t50

		if(M[69]>=1){ if(DxG[8] && !PSx[18]) {M[69]--;M[71]++;}}			//t51

		if(M[70]>=1){ if(DxD[8] && !PSx[18]) {M[70]--;M[72]++;}}			//t52

		if(M[71]>=1){ if(!PSx[16]) {M[71]--;M[73]++;}} 					//t53

		if(M[72]>=1){ if(!PSx[17]) {M[72]--;M[73]++;}} 					//t54

		//

		if(M[73]>=1){ if(PSx[18]) {M[73]--;M[95]++;}}					//VI


          	//A9 et A4


		if(M[95]>=1 && M[4]>=1 && M[9]>=1){if(DxD[9]){M[95]--;M[4]--;M[9]--;M[74]++;}} 	//t91 

		if(M[95]>=1 && M[9]>=1){if (DxG[9]){M[95]--;M[9]--;M[75]++;}} 			//t92    
		            
		if(M[74]>=1){if(DxG[9] && !PSx[8]){M[74]--;M[76]++;}} 				//t93   

		if(M[75]>=1){if(DxD[9] && !CPx[8]){M[75]--;M[77]++;}} 				//t94   

		if(M[76]>=1){if(!PSx[18]){M[76]--;M[78]++;}} 					//t95  

		if(M[77]>=1){if(!PSx[18]){M[77]--;M[79]++;}} 					//t96       

		//
				
		if(M[79]>=1 && M[10]>=1){if(PSx[19]){M[79]--;M[10]--;M[37]++;M[9]++;M[8]++;}} 	//VII  

		// A 10         

		if(M[37]>=1){if(!PSx[20] && DxD[10]){M[37]--;M[38]++;}} 			//t97 

		if(M[38]>=1){if(!PSx[19]){M[38]--;M[39]++;}} 					//t98  

		//

		if(M[39]>=1){if(PSx[20]){M[39]--;M[80]++;}} 					//VIII 

		if(M[58]>=1){if(PSx[20]){M[58]--;M[3]++;M[80]++;M[2]++;}} 			//VIII'  

             	// A11 et A12


               	if(M[80]>= 1 && M[11]>=1){	if(DxD[11]) {M[80]--;M[11]--;M[81]++;}		//t61
                                      	else if(DxG[11]) {M[80]--;M[11]--;M[82]++;}} 		//t62

		if(M[81]>=1){ if(DxG[11] && !CPx[10]) {M[81]--;M[83]++;}}			//t63

		if(M[82]>=1){ if(DxD[11] && !CPx[9]) {M[82]--;M[84]++;}}			//t64  

		if(M[83]>=1){ if(!PSx[20]) {M[83]--;M[85]++;}}					//t65

		if(M[84]>=1){ if(!PSx[20]) {M[84]--;M[86]++;}}					//t66

		if(M[85]>=1){ if(PSx[23]) {M[85]--;M[87]++;M[11]++;M[10]++;}}			//t67

		if(M[86]>=1){ if(PSx[21]) {M[86]--;M[88]++;M[11]++;M[10]++;}}			//t68

		if(M[87]>=1 && M[12]>=1){ if(1) {M[87]--;M[12]--;M[89]++;}}			//t69

		if(M[88]>=1 && M[12]>=1){ if(PSx[24]) {M[88]--;M[12]--;M[90]++;}}		//t70

		if(M[89]>=1){ if(DxG[12] && !PSx[1]) {M[89]--;M[91]++;}}			//t71

		if(M[90]>=1){ if(DxD[12] && !PSx[1]) {M[90]--;M[92]++;}}			//t72

		if(M[91]>=1){ if(!PSx[23]) {M[91]--;M[93]++;}}					//t73

		if(M[92]>=1){ if(!PSx[24]) {M[92]--;M[93]++;}}					//t74

		
      		// ACTIONNEURS //

		// Déverrouiller
                Dx[1]   = M[21]  || M[22] ;
		Dx[2]   = M[29]  || M[30] ;
                Dx[3]   = M[54]  || M[55] ;
		Dx[4]   = M[34]  || M[74] ;
		Dx[5]   = M[41]  || M[42] ;
		Dx[6]   = M[49]  || M[50] ;
                Dx[7]   = M[61]  || M[62] ;
		Dx[8]   = M[69]  || M[70] ;
		Dx[9]   = M[74]  || M[75] ;
		Dx[10]  = M[37]  || M[54] ;
                Dx[11]  = M[81]  || M[82] ;
		Dx[12]  = M[89]  || M[90] ;

		// Verrouiller
		Vx[1]   = M[23]  || M[24] ;
		Vx[2]   = M[31]  || M[32] ;
		Vx[3]   = M[56]  || M[57] ;
		Vx[4]   = M[35]  || M[76] ;
                Vx[5]   = M[43]  || M[44] ;
                Vx[6]   = M[51]  || M[52] ;
                Vx[7]   = M[63]  || M[64] ;
		Vx[8]   = M[71]  || M[72] ;
		Vx[9]   = M[76]  || M[77] ;
		Vx[10]  = M[38]  || M[56] ;
                Vx[11]  = M[83]  || M[84] ;
                Vx[12]  = M[91]  || M[92] ;

		// Aiguillage à droite
                RxD[1]  = M[22] ;
		RxD[2]  = M[30] ;
		RxD[3]  = M[55] ;
		RxD[4]  = M[34] ;
		RxD[5]  = M[42] ;
		RxD[6]  = M[50] ;
		RxD[7]  = M[62] ;
		RxD[8]  = M[70] ;
		RxD[9]  = M[75] ;
		RxD[10] = M[37] ;
		RxD[11] = M[82] ;
		RxD[12] = M[90] ;

		// Aiguillage à gauche
                RxG[1]  = M[21] ;
		RxG[2]  = M[29] ;
		RxG[3]  = M[54] ;
		RxG[4]  = M[74] ;
		RxG[5]  = M[41] ;
		RxG[6]  = M[49] ;
		RxG[7]  = M[61] ;
		RxG[8]  = M[69] ;
		RxG[9]  = M[74] ;
		RxG[10] = M[54] ;
		RxG[11] = M[81] ;
		RxG[12] = M[89] ;

		
		// Stops		
		STx[1]  = M[23] || M[24] ;
		STx[2]  = M[28] ;
		STx[3]  = M[28] ;
		STx[4]  = M[31] ;
		STx[5]  = M[32] ;
		STx[6]  = M[56] || M[57] ; 
		STx[7]  = M[35] ;
                STx[8]  = M[43] || M[44] ;
		STx[9]  = M[48] ;
		STx[10] = M[48] ;
		STx[11] = M[51] ;
		STx[12] = M[52] ;
		STx[13] = M[63] || M[64] ;
		STx[14] = M[68] ;
		STx[15] = M[68] ;
		STx[16] = M[71] ;
		STx[17] = M[72] ; 
		STx[18] = M[76] || M[77] ;
		STx[19] = M[38] ; 
		STx[20] = M[83] || M[84] ;
		STx[21] = M[88] ;
		STx[22] = M[88] ;
		STx[23] = M[91] ;
		STx[24] = M[92] ;
		
		


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
