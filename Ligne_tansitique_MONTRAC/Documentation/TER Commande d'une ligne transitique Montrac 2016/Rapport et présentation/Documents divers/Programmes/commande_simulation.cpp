#include "commande_simulation.h"
#include "sensorState.h"
#include "switchState.h"
#include "stopState.h"
#include <ros/ros.h>
#include <iostream>

using namespace std;

// Actualiser capteurs venant de la simulation pour le main
void Actualiser_Capteurs(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[],sensorState SensorSt)
{
	PSx[1]=SensorSt.PS[1];
	PSx[2]=SensorSt.CPI[1];
	PSx[3]=SensorSt.CPI[2];
	PSx[4]=SensorSt.PS[2];
	PSx[5]=SensorSt.PS[3];
	PSx[6]=SensorSt.PS[4];
	PSx[7]=SensorSt.PS[5];
	PSx[8]=SensorSt.PS[6];
	PSx[9]=SensorSt.CPI[3];
	PSx[10]=SensorSt.CPI[4];
	PSx[11]=SensorSt.PS[7];
	PSx[12]=SensorSt.PS[8];
	PSx[13]=SensorSt.PS[9];
	PSx[14]=SensorSt.CPI[5];
	PSx[15]=SensorSt.CPI[6];
	PSx[16]=SensorSt.PS[10];
	PSx[17]=SensorSt.PS[11];
	PSx[18]=SensorSt.PS[12];
	PSx[19]=SensorSt.PS[13];
	PSx[20]=SensorSt.PS[14];
	PSx[21]=SensorSt.CPI[7];
	PSx[22]=SensorSt.CPI[8];
	PSx[23]=SensorSt.PS[15];
	PSx[24]=SensorSt.PS[16];
	for(int i=1;i<13;i++) DxD[i]=SensorSt.DD[i];
	for(int i=1;i<13;i++) DxG[i]=SensorSt.DG[i];
	for(int i=1;i<11;i++) CPx[i]=SensorSt.CP[i];
	for(int i=1;i<9;i++) CPIx[i]=SensorSt.CPI[i];
}




// Actualiser actionneurs de la simulation venant du main
void Actualiser_Actionneurs(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[],stopState *stopSt,switchState *switchSt)
{
	for(int i=1;i<25;i++) {if(STx[i]) stopSt->go(i); else stopSt->stop(i);}
	for(int i=1;i<13;i++) if(RxD[i]) switchSt->turnRight(i);
	for(int i=1;i<13;i++) if(RxG[i]) switchSt->turnLeft(i);
	for(int i=1;i<9;i++) if(PIx[i]) ; // n'existe pas sur la simulation
	for(int i=1;i<13;i++) if(Vx[i]) switchSt->lockSwitch(i);
	for(int i=1;i<13;i++) if(Dx[i]) switchSt->unlockSwitch(i);
}



void Initialisation(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[],bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[])
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


// Touner un aiguillage a gauche
void left(switchState* switchSt,int num)
{
	switchSt->unlockSwitch(num);
	usleep(300000);
	switchSt->turnLeft(num);
	usleep(3000000);
	switchSt->lockSwitch(num);
}

// Tourner un aiguillage a droite
void right(switchState* switchSt,int num)
{
	switchSt->unlockSwitch(num);
	usleep(300000);
	switchSt->turnRight(num);
	usleep(3000000);
	switchSt->lockSwitch(num);
}

// Activer un stop
void stop(stopState* stopSt,int num)
{
	stopSt->stop(num);
}

// Desactiver un stop
void go(stopState* stopSt,int num)
{
	stopSt->go(num);
}

// Deplacer les navettes devant 2 stop pour l'initialisation de la commande
void Deplacer_navettes(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[],stopState *stopSt,switchState *switchSt,int numero_premier_stop,int numero_deuxieme_stop)
{
	for(int i=0;i<25;i++) STx[i]=1;
	STx[numero_premier_stop]=0;STx[numero_deuxieme_stop]=0;
	Actualiser_Actionneurs(STx,RxD,RxG,Vx,Dx,PIx,stopSt,switchSt);

	usleep(8000000);

	for(int i=0;i<25;i++) STx[i]=0;
	Actualiser_Actionneurs(STx,RxD,RxG,Vx,Dx,PIx,stopSt,switchSt);
}


