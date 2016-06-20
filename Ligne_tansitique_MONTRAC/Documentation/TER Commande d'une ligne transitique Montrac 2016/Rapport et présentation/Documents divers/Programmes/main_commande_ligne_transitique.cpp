#include "commande_ligne_transitique.h"
#include <ros/ros.h>

#include <unistd.h>

using namespace std;

#define NOMBRE_PLACE 20

int main(int argc, char **argv)
{

//initialisation du noeud ros et creation d'un handle associe au noeud
	ros::init(argc, argv, "commande");
	ros::NodeHandle noeud;

// Construction de la classe Commande_ligne
	Commande_ligne Cmd(noeud);

//frequence de la boucle
	ros::Rate loop_rate(15);


// Declaration des variables pour la MEF ou le RdP //

	/* Tableau marquage */
	int  M[NOMBRE_PLACE+1];

	/* Capteurs */
	bool PSx[25],DxD[13],DxG[13],CPx[11],CPIx[9];

	/* Actionneurs */
	bool STx[25],RxD[13],RxG[13],Vx[13],Dx[13],PIx[9];

// Initialisation variables //

	Cmd.Initialisation(PSx,DxD,DxG,CPx,CPIx,STx,RxD,RxG,Vx,Dx,PIx);


//////////////////////////////////////////////
//////////// Initialisation RdP //////////////
//////////////////////////////////////////////

	for (int i=0;i<=NOMBRE_PLACE;i++) M[i] = 0 ;

	M[17] = 2 ; //Nombre de navettes
	M[16] = 1 ;
	M[15] = 1 ;

//////////////////////////////////////////////
//////////////////////////////////////////////
//////////////////////////////////////////////




	while (ros::ok())
	{
		Cmd.Actualiser_Capteurs(PSx,DxD,DxG,CPx,CPIx);

		Afficher_capteurs(PSx,DxD,DxG,CPx,CPIx);
		Afficher_marquage_RdP(M,NOMBRE_PLACE);

		/////////////////////////////////////////////////
		////////////////////// RdP //////////////////////
		/////////////////////////////////////////////////

		//RdP pour les automates 1 et 2

        if(M[17]>=1 && M[16]>=1){ if(PSx[1]) {M[17]--;M[16]--;M[1]++;}}	//t1

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

		if(M[13]>=1){ if(PSx[20]) {M[13]--;M[14]++;}}	//t15

		if(M[14]>=1){ if(!PSx[20]) {M[14]--;M[17]++;M[15]++;}}	//t16


        // ACTIONNEURS

		Dx[1]   = M[2]  || M[3] ;
		Dx[2]   = M[9]  || M[10] ;
		Vx[1]   = M[4]  || M[5] ;
		Vx[2]   = M[11] || M[12] ;

		RxD[1]  = M[3] ;
		RxD[2]  = M[10] ;
		RxG[1]  = M[2] ;
		RxG[2]  = M[9] ;

		STx[1]  = M[4] || M[5] ;
		STx[2]  = M[8] ;
		STx[3]  = M[8] ;
		STx[4]  = M[11] ;
		STx[5]  = M[12] ;
		STx[20] = M[14] ;
		STx[21] = M[17] ;
		STx[22] = M[17] ;
		STx[23] = M[17] ;
		STx[24] = M[17] ;

 		//////////////////////////////////////////////////
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////

		Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);

		Cmd.Actualiser_Actionneurs(STx,RxD,RxG,Vx,Dx,PIx);

		///////////////////////////////////
		//////////// fin code /////////////
		///////////////////////////////////

		Cmd.publish(); // Publication des actionneurs

		ros::spinOnce(); // Activation des fonctions Callback si messages entrants
		loop_rate.sleep(); // Synchronisation de la boucle

	}
	return 0;
}
