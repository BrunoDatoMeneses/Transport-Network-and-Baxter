#include <ros/ros.h>
#include "actionneurs.h"
#include "capteurs.h"
#include <commande_locale/Msg_StopControl.h>
#include "commande_locale/Msg_SwitchControl.h"


// Constructeur
Actionneurs::Actionneurs(ros::NodeHandle noeud)
{
	// Publisher
	pub_actionneurs_ligne = noeud.advertise<commande::Actionneurs>("/commande/Ligne_transitique/Actionneurs", 1);
	pub_actionneurs_simu_aguillages = noeud.advertise<commande_locale::Msg_SwitchControl>("/commande/Simulation/Actionneurs_aiguillages", 1);
	pub_actionneurs_simu_stops = noeud.advertise<commande_locale::Msg_StopControl>("/commande/Simulation/Actionneurs_stops", 1);

	Actionneurs_ligne=0;

	for(int i=1;i<=24;i++) actionneurs_simulation_Stop.STOP[i] = 1;
	for(int i=1;i<=24;i++) actionneurs_simulation_Stop.GO[i] = 0;

	for(int i=1;i<=12;i++) actionneurs_simulation_Aguillages.LOCK[i] = 0;
	for(int i=1;i<=12;i++) actionneurs_simulation_Aguillages.RD[i] = 0;
	for(int i=1;i<=12;i++) actionneurs_simulation_Aguillages.RG[i] = 0;
}


// Destructeur
Actionneurs::~Actionneurs()
{
}

// Mettre a jour les actionneurs de la ligne transitique et de la simulation
void Actionneurs::Envoyer(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[])
{
    // Ligne transitique
	Actionneurs::Ecrire_ligne_STx(STx);
	Actionneurs::Ecrire_ligne_RxD(RxD);
	Actionneurs::Ecrire_ligne_RxG(RxG);
	Actionneurs::Ecrire_ligne_PIx(PIx);
	Actionneurs::Ecrire_ligne_Vx(Vx);
	Actionneurs::Ecrire_ligne_Dx(Dx);

    // Simulation
	for(int i=1;i<=24;i++) actionneurs_simulation_Stop.STOP[i] = !STx[i];
	for(int i=1;i<=24;i++) actionneurs_simulation_Stop.GO[i] = STx[i];
	for(int i=1;i<=12;i++) actionneurs_simulation_Aguillages.LOCK[i] = !Vx[i] && Dx[i];
	for(int i=1;i<=12;i++) actionneurs_simulation_Aguillages.RD[i] = RxD[i];
	for(int i=1;i<=12;i++) actionneurs_simulation_Aguillages.RG[i] = RxG[i];

	Actionneurs::publish_actionneurs_ligne();
	Actionneurs::publish_actionneurs_simulation();
}

// Mettre a jour les actionneurs Stop sur la ligne transitique
void Actionneurs::Ecrire_ligne_STx(bool STx[])
{
	WRITE(&Actionneurs_ligne,STx[1],8);
	WRITE(&Actionneurs_ligne,STx[2],9);
	WRITE(&Actionneurs_ligne,STx[3],10);
	WRITE(&Actionneurs_ligne,STx[4],12);
	WRITE(&Actionneurs_ligne,STx[5],11);
	WRITE(&Actionneurs_ligne,STx[20],24);
	WRITE(&Actionneurs_ligne,STx[21],25);
	WRITE(&Actionneurs_ligne,STx[22],26);
	WRITE(&Actionneurs_ligne,STx[23],28);
	WRITE(&Actionneurs_ligne,STx[24],27);
}

// Mettre a jour les actionneurs Aiguillage a droite sur la ligne transitique
void Actionneurs::Ecrire_ligne_RxD(bool RxD[])
{
	WRITE(&Actionneurs_ligne,RxD[1],0);
	WRITE(&Actionneurs_ligne,RxD[2],4);
	WRITE(&Actionneurs_ligne,RxD[11],16);
	WRITE(&Actionneurs_ligne,RxD[12],20);
}

// Mettre a jour les actionneur Aguillage a gauche sur la ligne transitique
void Actionneurs::Ecrire_ligne_RxG(bool RxG[])
{
	WRITE(&Actionneurs_ligne,RxG[1],1);
	WRITE(&Actionneurs_ligne,RxG[2],5);
	WRITE(&Actionneurs_ligne,RxG[11],17);
	WRITE(&Actionneurs_ligne,RxG[12],21);
}

// Mettre a jour les actionneur Ergots sur la ligne transitique
void Actionneurs::Ecrire_ligne_PIx(bool PIx[])
{
	WRITE(&Actionneurs_ligne,PIx[1],13);
	WRITE(&Actionneurs_ligne,PIx[2],14);
	WRITE(&Actionneurs_ligne,PIx[7],29);
	WRITE(&Actionneurs_ligne,PIx[8],30);
}

// Mettre a jour les actionneurs Verrouiller sur la ligne transitique
void Actionneurs::Ecrire_ligne_Vx(bool Vx[])
{
	WRITE(&Actionneurs_ligne,Vx[1],2);
	WRITE(&Actionneurs_ligne,Vx[2],6);
	WRITE(&Actionneurs_ligne,Vx[11],18);
	WRITE(&Actionneurs_ligne,Vx[12],22);
}

// Mettre a jour les actionneurs Deverrouiller sur la ligne transitique
void Actionneurs::Ecrire_ligne_Dx(bool Dx[])
{
	WRITE(&Actionneurs_ligne,Dx[1],3);
	WRITE(&Actionneurs_ligne,Dx[2],7);
	WRITE(&Actionneurs_ligne,Dx[11],19);
	WRITE(&Actionneurs_ligne,Dx[12],23);
}

// Publier le message des actionneurs pour la ligne transitique
void Actionneurs::publish_actionneurs_ligne()
{
	commande::Actionneurs msg;
	msg.actionneurs=Actionneurs_ligne;
	pub_actionneurs_ligne.publish(msg);
}

// Publier les messages des actionneurs pour la simulation
void Actionneurs::publish_actionneurs_simulation()
{
	pub_actionneurs_simu_stops.publish(actionneurs_simulation_Stop);
	pub_actionneurs_simu_aguillages.publish(actionneurs_simulation_Aguillages);
}

// Modifier un seul bit dans un registre
void WRITE(long int *registre,bool donnee,int numero_bit)
{
	if (MASK(*registre,numero_bit)!=donnee)
		if(donnee==1) *registre += donnee*pow(2,numero_bit);
		else *registre -= pow(2,numero_bit);
}



