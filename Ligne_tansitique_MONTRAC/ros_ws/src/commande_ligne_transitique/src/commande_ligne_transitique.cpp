#include "commande_ligne_transitique.h"
#include "commande_ligne_transitique/Actionneurs.h"
#include "commande_ligne_transitique/Capteurs.h"
#include <iostream>
#include <ros/ros.h>

using namespace std;


// Constructeur
Commande_ligne::Commande_ligne(ros::NodeHandle noeud)
{
	// Publishers
	pub_actionneurs = noeud.advertise<commande_ligne_transitique::Actionneurs>("/commande/Ligne_transitique/Actionneurs", 1);

	// Subscriber
	sub_capteurs = noeud.subscribe("/commande/Ligne_transitique/Capteurs", 1, &Commande_ligne::Callback_capteurs,this);

	CAPTEURS=0;
	ACTIONNEURS=0;
}


// Destructeur
Commande_ligne::~Commande_ligne()
{
}


void Commande_ligne::Callback_capteurs(const commande_ligne_transitique::Capteurs msg)
{
	CAPTEURS=msg.capteurs;	
}

void Commande_ligne::publish()
{
	commande_ligne_transitique::Actionneurs msg;
	msg.actionneurs=ACTIONNEURS;
	pub_actionneurs.publish(msg);
}

void Commande_ligne::Initialisation(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[],bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[])
{
	for(int i=0;i<25;i++) PSx[i]=0;
	for(int i=0;i<13;i++) DxD[i]=0;
	for(int i=0;i<13;i++) DxG[i]=0;
	for(int i=0;i<11;i++) CPx[i]=0;
	for(int i=0;i<9;i++) CPIx[i]=0;

	for(int i=0;i<25;i++) STx[i]=0;
	for(int i=0;i<13;i++) RxD[i]=0;
	for(int i=0;i<13;i++) RxG[i]=0;
	for(int i=0;i<13;i++) Vx[i]=0;
	for(int i=0;i<13;i++) Dx[i]=0;
	for(int i=0;i<9;i++) PIx[i]=0;
}


//// Actualiser Capteurs ////


void Commande_ligne::Actualiser_Capteurs_PSx(bool PSx[])
{
	PSx[1]=MASK(CAPTEURS,0);
	PSx[2]=MASK(CAPTEURS,1);
	PSx[3]=MASK(CAPTEURS,2);
	PSx[4]=MASK(CAPTEURS,4);
	PSx[5]=MASK(CAPTEURS,3);
	PSx[6]=MASK(CAPTEURS,13);
	PSx[20]=MASK(CAPTEURS,16);
	PSx[21]=MASK(CAPTEURS,17);
	PSx[22]=MASK(CAPTEURS,18);
	PSx[23]=MASK(CAPTEURS,20);
	PSx[24]=MASK(CAPTEURS,19);
}

void Commande_ligne::Actualiser_Capteurs_DxD(bool DxD[])
{
	DxD[1]=MASK(CAPTEURS,5);
	DxD[2]=MASK(CAPTEURS,10);
	DxD[11]=MASK(CAPTEURS,21);
	DxD[12]=MASK(CAPTEURS,26);
}

void Commande_ligne::Actualiser_Capteurs_DxG(bool DxG[])
{
	DxG[1]=MASK(CAPTEURS,6);
	DxG[2]=MASK(CAPTEURS,11);
	DxG[11]=MASK(CAPTEURS,22);
	DxG[12]=MASK(CAPTEURS,27);
}

void Commande_ligne::Actualiser_Capteurs_CPx(bool CPx[])
{
	CPx[1]=MASK(CAPTEURS,7);
	CPx[2]=MASK(CAPTEURS,12);
	CPx[9]=MASK(CAPTEURS,23);
	CPx[10]=MASK(CAPTEURS,28);
}

void Commande_ligne::Actualiser_Capteurs_CPIx(bool CPIx[])
{
	CPIx[1]=MASK(CAPTEURS,8);
	CPIx[2]=MASK(CAPTEURS,9);
	CPIx[7]=MASK(CAPTEURS,24);
	CPIx[8]=MASK(CAPTEURS,25);
}


void Commande_ligne::Actualiser_Capteurs(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[])
{
	Commande_ligne::Actualiser_Capteurs_PSx(PSx);
	Commande_ligne::Actualiser_Capteurs_DxD(DxD);
	Commande_ligne::Actualiser_Capteurs_DxG(DxG);
	Commande_ligne::Actualiser_Capteurs_CPx(CPx);
	Commande_ligne::Actualiser_Capteurs_CPIx(CPIx);
}


//// Actualiser Actionneurs ////

void Commande_ligne::Actualiser_Actionneurs_STx(bool STx[])
{
	WRITE(&ACTIONNEURS,STx[1],8);
	WRITE(&ACTIONNEURS,STx[2],9);
	WRITE(&ACTIONNEURS,STx[3],10);
	WRITE(&ACTIONNEURS,STx[4],12);
	WRITE(&ACTIONNEURS,STx[5],11);
	WRITE(&ACTIONNEURS,STx[20],24);
	WRITE(&ACTIONNEURS,STx[21],25);
	WRITE(&ACTIONNEURS,STx[22],26);
	WRITE(&ACTIONNEURS,STx[23],28);
	WRITE(&ACTIONNEURS,STx[24],27);
}



void Commande_ligne::Actualiser_Actionneurs_RxD(bool RxD[])
{
	WRITE(&ACTIONNEURS,RxD[1],0);
	WRITE(&ACTIONNEURS,RxD[2],4);
	WRITE(&ACTIONNEURS,RxD[11],16);
	WRITE(&ACTIONNEURS,RxD[12],20);
}



void Commande_ligne::Actualiser_Actionneurs_RxG(bool RxG[])
{
	WRITE(&ACTIONNEURS,RxG[1],1);
	WRITE(&ACTIONNEURS,RxG[2],5);
	WRITE(&ACTIONNEURS,RxG[11],17);
	WRITE(&ACTIONNEURS,RxG[12],21);
}


void Commande_ligne::Actualiser_Actionneurs_PIx(bool PIx[])
{
	WRITE(&ACTIONNEURS,PIx[1],13);
	WRITE(&ACTIONNEURS,PIx[2],14);
	WRITE(&ACTIONNEURS,PIx[7],29);
	WRITE(&ACTIONNEURS,PIx[8],30);
}

void Commande_ligne::Actualiser_Actionneurs_Vx(bool Vx[])
{
	WRITE(&ACTIONNEURS,Vx[1],2);
	WRITE(&ACTIONNEURS,Vx[2],6);
	WRITE(&ACTIONNEURS,Vx[11],18);
	WRITE(&ACTIONNEURS,Vx[12],22);
}

void Commande_ligne::Actualiser_Actionneurs_Dx(bool Dx[])
{
	WRITE(&ACTIONNEURS,Dx[1],3);
	WRITE(&ACTIONNEURS,Dx[2],7);
	WRITE(&ACTIONNEURS,Dx[11],19);
	WRITE(&ACTIONNEURS,Dx[12],23);
}


void Commande_ligne::Actualiser_Actionneurs(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[])
{
	Commande_ligne::Actualiser_Actionneurs_STx(STx);
	Commande_ligne::Actualiser_Actionneurs_RxD(RxD);
	Commande_ligne::Actualiser_Actionneurs_RxG(RxG);
	Commande_ligne::Actualiser_Actionneurs_PIx(PIx);
	Commande_ligne::Actualiser_Actionneurs_Vx(Vx);
	Commande_ligne::Actualiser_Actionneurs_Dx(Dx);
}


////////////////// Outils ///////////////////////////

bool MASK(long int registre,int numero_bit)
{
	return (bool)((registre & (long int)(pow(2,numero_bit)))/pow(2,numero_bit));
}

void WRITE(long int *registre,bool donnee,int numero_bit)
{
	if (MASK(*registre,numero_bit)!=donnee) 
		if(donnee==1) *registre += donnee*pow(2,numero_bit);
		else *registre -= pow(2,numero_bit);
}


void Afficher_capteurs(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[])
{
	ROS_INFO("CAPTEURS");
	for(int i=1;i<25;i++) {cout << "PS" << i << "=" <<PSx[i]<<"  ";}cout << endl;
	for(int i=1;i<13;i++) {cout << "D" << i << "D" << "=" <<DxD[i]<<"  ";}cout << endl;
	for(int i=1;i<13;i++) {cout << "D" << i << "G" << "=" <<DxG[i]<<"  ";}cout << endl;
	for(int i=1;i<11;i++) {cout << "CP" << i << "=" <<CPx[i]<<"  ";}cout << endl;
	for(int i=1;i<9;i++) {cout << "CPI" << i << "=" <<CPIx[i]<<"  ";}cout << endl;
	cout << endl;
}

void Afficher_actionneurs(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[])
{
	ROS_INFO("ACTIONNEURS");
	for(int i=1;i<25;i++) {cout << "ST" << i << "=" <<STx[i]<<"  ";} cout << endl;
	for(int i=1;i<13;i++) {cout << "R" << i << "D" << "=" <<RxD[i]<<"  ";} cout << endl;
	for(int i=1;i<13;i++) {cout << "R" << i << "G" << "=" <<RxG[i]<<"  ";} cout << endl;
	for(int i=1;i<13;i++) {cout << "V" << i << "=" <<Vx[i]<<"  ";} cout << endl;
	for(int i=1;i<13;i++) {cout << "D" << i << "=" <<Dx[i]<<"  ";} cout << endl;
	for(int i=1;i<9;i++) {cout << "PI" << i << "=" <<PIx[i]<<"  ";} cout << endl;
	cout<<endl<<endl;
	cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " <<endl<<endl;
}

void Afficher_marquage_RdP(int M[],int nombre_places)
{
	ROS_INFO("Marquage RdP");
	for(int i=1;i<=nombre_places;i++) {cout << "M[" << i << "]=" <<M[i]<<"  ";}
	cout << endl << endl;
}






