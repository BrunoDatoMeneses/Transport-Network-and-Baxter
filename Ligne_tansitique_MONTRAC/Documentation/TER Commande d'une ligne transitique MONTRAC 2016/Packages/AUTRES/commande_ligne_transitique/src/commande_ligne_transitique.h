#ifndef COMMANDE_LIGNE
#define COMMANDE_LIGNE

#include "commande_ligne_transitique/Actionneurs.h"
#include "commande_ligne_transitique/Capteurs.h"
#include <ros/ros.h>


class Commande_ligne
{
private:

	ros::Publisher pub_actionneurs;
	ros::Subscriber sub_capteurs;
	long int CAPTEURS;
	long int ACTIONNEURS;


public:
	
	Commande_ligne(ros::NodeHandle noeud);
	~Commande_ligne();
	void Callback_capteurs(const commande_ligne_transitique::Capteurs msg);
	void publish();

	void Initialisation(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[],bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[]);

	void Actualiser_Capteurs_PSx(bool PSx[]);
	void Actualiser_Capteurs_DxD(bool DxD[]);
	void Actualiser_Capteurs_DxG(bool DxG[]);
	void Actualiser_Capteurs_CPx(bool CPx[]);
	void Actualiser_Capteurs_CPIx(bool CPIx[]);
	void Actualiser_Capteurs(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[]);

	void Actualiser_Actionneurs_STx(bool STx[]);
	void Actualiser_Actionneurs_RxD(bool RxD[]);
	void Actualiser_Actionneurs_RxG(bool RxG[]);
	void Actualiser_Actionneurs_Vx(bool Vx[]);
	void Actualiser_Actionneurs_Dx(bool Dx[]);
	void Actualiser_Actionneurs_PIx(bool PIx[]);
	void Actualiser_Actionneurs(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[]);

};


// Outils divers //
bool MASK(long int registre,int numero_bit);
void WRITE(long int *registre,bool donnee,int numero_bit);
void Afficher_capteurs(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[]);
void Afficher_actionneurs(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[]);
void Afficher_marquage_RdP(int M[],int nombre_places);








#endif
