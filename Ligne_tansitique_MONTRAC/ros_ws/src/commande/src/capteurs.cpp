#include <ros/ros.h>
#include "capteurs.h"
#include <commande_locale/Msg_SensorState.h>


// Constructeur
Capteurs::Capteurs(ros::NodeHandle noeud)
{
	// Subscriber
	sub_capteurs_ligne = noeud.subscribe("/commande/Ligne_transitique/Capteurs", 1, &Capteurs::Callback_capteurs_ligne,this);
	sub_capteurs_simu = noeud.subscribe("/commande/Simulation/Capteurs", 1, &Capteurs::Callback_capteurs_simulation,this);

	SIMULATION=false;
	LIGNE=false;
	
	for(int i=0;i<25;i++) PSx[i]=0;
	for(int i=0;i<13;i++) DxD[i]=0;
	for(int i=0;i<13;i++) DxG[i]=0;
	for(int i=0;i<11;i++) CPx[i]=0;
	for(int i=0;i<9;i++) CPIx[i]=0;	
}


// Destructeur
Capteurs::~Capteurs()
{
}


void Capteurs::Callback_capteurs_ligne(const commande::Capteurs msg)
{
	long int CAPTEURS=msg.capteurs;
	SIMULATION=false;
	LIGNE=true;
	Capteurs::Actualiser_PSx(CAPTEURS);
	Capteurs::Actualiser_DxD(CAPTEURS);
	Capteurs::Actualiser_DxG(CAPTEURS);
	Capteurs::Actualiser_CPx(CAPTEURS);
	Capteurs::Actualiser_CPIx(CAPTEURS);
}

void Capteurs::Actualiser_PSx(long int CAPTEURS)
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

void Capteurs::Actualiser_DxD(long int CAPTEURS)
{
	DxD[1]=MASK(CAPTEURS,5);
	DxD[2]=MASK(CAPTEURS,10);
	DxD[11]=MASK(CAPTEURS,21);
	DxD[12]=MASK(CAPTEURS,26);
}

void Capteurs::Actualiser_DxG(long int CAPTEURS)
{
	DxG[1]=MASK(CAPTEURS,6);
	DxG[2]=MASK(CAPTEURS,11);
	DxG[11]=MASK(CAPTEURS,22);
	DxG[12]=MASK(CAPTEURS,27);
}

void Capteurs::Actualiser_CPx(long int CAPTEURS)
{
	CPx[1]=MASK(CAPTEURS,7);
	CPx[2]=MASK(CAPTEURS,12);
	CPx[9]=MASK(CAPTEURS,23);
	CPx[10]=MASK(CAPTEURS,28);
}

void Capteurs::Actualiser_CPIx(long int CAPTEURS)
{
	CPIx[1]=MASK(CAPTEURS,8);
	CPIx[2]=MASK(CAPTEURS,9);
	CPIx[7]=MASK(CAPTEURS,24);
	CPIx[8]=MASK(CAPTEURS,25);
}

void Capteurs::Callback_capteurs_simulation(const commande_locale::Msg_SensorState::ConstPtr& msg)
{
	SIMULATION=true;
	LIGNE=false;

	PSx[1]=msg->PS[1];
	PSx[2]=msg->CPI[1];
	PSx[3]=msg->CPI[2];
	PSx[4]=msg->PS[2];
	PSx[5]=msg->PS[3];
	PSx[6]=msg->PS[4];
	PSx[7]=msg->PS[5];
	PSx[8]=msg->PS[6];
	PSx[9]=msg->CPI[3];
	PSx[10]=msg->CPI[4];
	PSx[11]=msg->PS[7];
	PSx[12]=msg->PS[8];
	PSx[13]=msg->PS[9];
	PSx[14]=msg->CPI[5];
	PSx[15]=msg->CPI[6];
	PSx[16]=msg->PS[10];
	PSx[17]=msg->PS[11];
	PSx[18]=msg->PS[12];
	PSx[19]=msg->PS[13];
	PSx[20]=msg->PS[14];
	PSx[21]=msg->CPI[7];
	PSx[22]=msg->CPI[8];
	PSx[23]=msg->PS[15];
	PSx[24]=msg->PS[16];
	for(int i=1;i<13;i++) DxD[i]=msg->DD[i];
	for(int i=1;i<13;i++) DxG[i]=msg->DG[i];
	for(int i=1;i<11;i++) CPx[i]=msg->CP[i];
	for(int i=1;i<9;i++) CPIx[i]=msg->CPI[i];
}


void Capteurs::Actualiser(bool PS[],bool DD[],bool DG[],bool CP[],bool CPI[])
{
	for(int i=1;i<25;i++) PS[i]=PSx[i];
	for(int i=1;i<13;i++) DD[i]=DxD[i];
	for(int i=1;i<13;i++) DG[i]=DxG[i];
	for(int i=1;i<11;i++) CP[i]=CPx[i];
	for(int i=1;i<9;i++) CPI[i]=CPIx[i];
}


bool MASK(long int registre,int numero_bit)
{
	return (bool)((registre & (long int)(pow(2,numero_bit)))/pow(2,numero_bit));
}


