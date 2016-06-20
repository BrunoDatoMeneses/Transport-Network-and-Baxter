#include "capteurs.h"
#include "actionneurs.h"
#include "commande.h"
#include <ros/ros.h>
#include <unistd.h>

using namespace std;

#define NOMBRE_PLACE ?

int main(int argc, char **argv)
{

//initialisation du noeud ros et creation d'un handle associe au noeud
	ros::init(argc, argv, "commande");
	ros::NodeHandle noeud;

//creation et initialisation des objets Capteur et Actionneurs

	Capteurs Capteurs(noeud);

	Actionneurs Actionneurs(noeud);

	ros::Rate loop_rate(25); //frequence de la boucle



// Declaration des variables pour la MEF ou le RdP //

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
	//M[?]  = ?;

	// Disponibilite aiguillages
	//M[?] = 1;
	//M[?] = 1;
	//M[?] = 1;


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

		// Deplacement des navettes si on utilise la simulation
		if(Capteurs.SIMULATION==true && Deplacement_effectue==0)
		{
			Deplacer_navettes(Actionneurs,STx,RxD,RxG,Vx,Dx,PIx,5);

            // Mettre la simulation dans la meme configuration que la ligne
            // API 1 et 2 seulement dans notre cas
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

        // Mise en oeuvre directe ou M parmi N //
        // .
		// .
		// .



        // ACTIONNEURS //

        // Deverrouiller
		//Dx[1]   = M[?] ;
		// .
		// .
		// .
        //Dx[12]   = M[?] ;

        // Verrouiller
		//Vx[1]   = M[?] ;
		// .
		// .
		// .
        //Vx[12]   = M[?] ;

        // Aiguillages
		//RxD[1]  = M[?] ;
		// .
		// .
		// .
		//RxD[12]  = M[?] ;

		//RxG[1]  = M[?] ;
		// .
		// .
		// .
		//RxG[12]  = M[?] ;

        // Stops
		//STx[1]  = M[?] ;
		// .
		// .
		// .
		//STx[24]  = M[?] ;

        // Ergots
        //PIx[1] = M[?] ;
        // .
		// .
		// .
		//PIx[8] = M[?] ;


 		//////////////////////////////////////////////////
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////

		Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);

		Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);

		///////////////////////////////////
		//////////// fin code /////////////
		///////////////////////////////////

		ros::spinOnce(); //permet aux fonction callback de ros dans les objets d'etres appelees
		loop_rate.sleep(); //permet de synchroniser la boucle while
	}

	return 0;

}
