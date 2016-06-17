#include "scenario.h"
#include "sensorState.h"
#include "switchState.h"
#include "stopState.h"
#include <ros/ros.h>

using namespace std;

#define NOMBRE_ETATS 20


int main(int argc, char **argv)
{
	ros::init(argc, argv, "noeud_scenario");
	ros::NodeHandle noeud;	

	// Création des variables pour la MEF ou le RdP //

	/* Etats présents et états suivants */
	bool EP[NOMBRE_ETATS],ES[NOMBRE_ETATS];

	/* Capteurs */
	bool PS1(0),PS2(0),PS3(0),PS4(0),PS5(0),PS6(0),PS20(0),PS21(0),PS22(0),PS23(0),PS24(0); //Capteurs stop
	bool D1d(0),D2d(0),D11d(0),D12d(0); //Capteurs position aiguillage à droite
	bool D1g(0),D2g(0),D11g(0),D12g(0); //Capteurs position aiguillage à gauche
	bool CP1(0),CP2(0),CP9(0),CP10(0); //Capteurs position
	bool CPI1(0),CPI2(0),CPI7(0),CPI8(0); //Capteurs ergots

	/* Actionneurs */
	bool ST1(0),ST2(0),ST3(0),ST4(0),ST5(0),ST20(0),ST21(0),ST22(0),ST23(0),ST24(0); //Actionneurs stop
	bool R1D(0),R2D(0),R11D(0),R12D(0); //Actionneurs aiguillage à droite
	bool R1G(0),R2G(0),R11G(0),R12G(0); //Actionneurs aiguillage à gauche
	bool V1(0),V2(0),V11(0),V12(0); //Actionneurs verrouiller aiguillage
	bool D1(0),D2(0),D11(0),D12(0); //Actionneurs déverrouiller aiguillage
	bool PI1(0),PI2(0),PI7(0),PI8(0); //Actionneurs blocages sur poste de travail


	//création et initialisation des objets Capteur, Aiguillage et point d'arret pour la simulation
	sensorState SensorSt;
	SensorSt.init(noeud);

	switchState switchSt;
	switchSt.init(noeud);

	stopState stopSt;
	stopSt.init(noeud);

	Scenario Scn(noeud);

	ros::Rate loop_rate(0.5);

	//Initialisation

		EP[0] = true ;
		EP[1] = false;
		EP[2] = false;
		EP[3] = false;
		EP[4] = false;
		EP[5] = false;
		EP[6] = false;
		EP[7] = false;
		EP[8] = false;

		EP[10] = true ;
		EP[11] = false;
		EP[12] = false;
		EP[13] = false;
		EP[14] = false;
		EP[15] = false;
		EP[16] = false;
		EP[17] = false;
		EP[18] = false;
	
	while (ros::ok()) // Tant que ROS est actif,
	{
		Scn.Actualiser_Capteurs_PSx(&PS1,&PS2,&PS3,&PS4,&PS5,&PS6,&PS20,&PS21,&PS22,&PS23,&PS24);
		Scn.Actualiser_Capteurs_Dxd(&D1d,&D2d,&D11d,&D12d);
		Scn.Actualiser_Capteurs_Dxg(&D1g,&D2g,&D11g,&D12g);
		Scn.Actualiser_Capteurs_CPx(&CP1,&CP2,&CP9,&CP10);
		Scn.Actualiser_Capteurs_CPIx(&CPI1,&CPI2,&CPI7,&CPI8);

	// Affichage des capteurs //
	cout <<"PS1="<<PS1<<"  "<<"PS2="<<PS2<<"  "<<"PS3="<<PS3<<"  "<<"PS4="<<PS4<<"  "<<"PS5="<<PS5<<"  "<<"PS6="<<PS6<<"  "<<"PS20="<<PS20<<"  "<<"PS21="<<PS21<<"  "<<"PS22="<<PS22<<"  "<<"PS23="<<PS23<<"  "<<"PS24="<<PS24<<"  "<<endl;
	cout <<"D1d="<<D1d<<"  "<<"D2d="<<D2d<<"  "<<"D11d="<<D11d<<"  "<<"D12d="<<D12d<<"  "<<endl;
	cout <<"D1g="<<D1g<<"  "<<"D2g="<<D2g<<"  "<<"D11g="<<D11g<<"  "<<"D12g="<<D12g<<"  "<<endl;
	cout <<"CP1="<<CP1<<"  "<<"CP2="<<CP2<<"  "<<"CP9="<<CP9<<"  "<<"CP10="<<CP10<<"  "<<endl;
	cout <<"CPI1="<<CPI1<<"  "<<"CPI2="<<CPI2<<"  "<<"CPI7="<<CPI7<<"  "<<"CPI8="<<CPI8<<"  "<<endl;


		ROS_INFO("Etats MEF");
		for(int i=0;i<9;i++) 
		{
			cout << "EP[" << i << "]=" <<EP[i]<<"    ";
		}
		cout << endl;
		for(int i=10;i<19;i++) 
		{
			cout << "EP[" << i << "]=" <<EP[i]<<"   ";
		}
		cout << endl << endl;

		/////////
		// MEF //
		/////////

	//FMG pour l'automate 1

                // BLOC F 

		ES[0] =  (EP[8] & PS6) | (EP[0] & (!(PS1))) ;
		ES[1] =  (EP[0] & PS1) | (EP[1] & (!(D1d))) ;
		ES[2] =  EP[1] && D1d || EP[2] && (!(PS5)) ;
		ES[3] =  EP[2] && PS5 || EP[3] && (!(D2d)) ; 	
		ES[4] =  EP[3] && D2d || EP[4] && (!PS1) ;
		ES[5] =  EP[4] && PS1 || EP[5] && (!D1g) ;
		ES[6] =  EP[5] && D1g || EP[6] && (!PS4) ;
	        ES[7] =  EP[6] && PS4 || EP[7] && (!D2g) ;
		ES[8] =  EP[7] && D2g || EP[8] && (!PS6) ;

		ES[10] =  EP[18] && PS1   || EP[10] && (!(PS20)) ;
		ES[11] =  EP[10] && PS20  || EP[11] && (!(D11d)) ;
		ES[12] =  EP[11] && D11d  || EP[12] && (!(PS24)) ;
		ES[13] =  EP[12] && PS24  || EP[13] && (!(D12d)) ; 	
		ES[14] =  EP[13] && D12d  || EP[14] && (!PS20) ;
		ES[15] =  EP[14] && PS20  || EP[15] && (!D11g) ;
		ES[16] =  EP[15] && D11g  || EP[16] && (!PS23) ;
	        ES[17] =  EP[16] && PS23  || EP[17] && (!D12g) ;
		ES[18] =  EP[17] && D12g  || EP[18] && (!PS1)  ;

                // BLOC M 

               for( int i = 0 ; i < 19 ; i++ )
		      EP[i] = ES[i] ;
		
                // BLOC G 

		D1   = EP[1] || EP[5] ;
		V1   = EP[2] || EP[6] ;
		D2   = EP[3] || EP[7] ;
		V2   = EP[4] || EP[8] ;
		R1D  = EP[1] ;
		R2D  = EP[3] ;
		R1G  = EP[5] ;
		R2G  = EP[7] ;
		ST1  = EP[6] || EP[2] ; 
		ST2  = EP[2] ;
		ST3  = EP[2] ;
		ST4  = EP[8] ;

		D11   = EP[11] || EP[15] ;
		V11   = EP[12] || EP[16] ;
		D12   = EP[13] || EP[17] ;
		V12   = EP[14] || EP[18] ;
		R11D  = EP[11] ;
		R12D  = EP[13] ;
		R11G  = EP[15] ;
		R12G  = EP[17] ;
		ST20  = EP[12] || EP[16] ; 
		ST21  = EP[12] ;
		ST22  = EP[12] ;
		ST23  = EP[18] ;
		ST24  = EP[14] ;

 	//****************************************
		
		ROS_INFO("Etats MEF");
		for(int i=0;i<9;i++) 
		{
			cout << "ES[" << i << "]=" <<ES[i]<<"    ";
		}
		cout << endl;
		for(int i=10;i<19;i++) 
		{
			cout << "ES[" << i << "]=" <<ES[i]<<"   ";
		}
		cout << endl << endl;

		Scn.Actualiser_Actionneurs_STx(ST1,ST2,ST3,ST4,ST5,ST20,ST21,ST22,ST23,ST24);
		Scn.Actualiser_Actionneurs_RxD(R1D,R2D,R11D,R12D);
		Scn.Actualiser_Actionneurs_RxG(R1G,R2G,R11G,R12G);
		Scn.Actualiser_Actionneurs_Vx(V1,V2,V11,V12);
		Scn.Actualiser_Actionneurs_Dx(D1,D2,D11,D12);
		Scn.Actualiser_Actionneurs_PIx(PI1,PI2,PI7,PI8);

		Scn.publish();
		
		ros::spinOnce(); // on lance les callback correspondant aux messages entrants.

		loop_rate.sleep(); //permet de synchroniser la boucle while avec la fréquence indiquée dans le loop_rate
	}

	return 0;
}
