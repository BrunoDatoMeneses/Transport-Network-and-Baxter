#include "commande.h"
#include "actionneurs.h" 
#include "commande.h"
#include <ros/ros.h>
#include <iostream>

using namespace std;

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


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
	cout <<"~~~~~~ CAPTEURS ~~~~~~~~~"<<endl<<endl;
	for(int i=1;i<25;i++) {if(PSx[i]){cout << BOLDGREEN << "PS" << i << "=" <<PSx[i]<< RESET <<"  ";} else {cout << "PS" << i << "=" <<PSx[i]<<"  ";}}cout << endl;
	for(int i=1;i<13;i++) {if(DxD[i]){cout << BOLDGREEN << "D" << i << "D" << "=" <<DxD[i]<< RESET <<"  ";} else {cout << "D" << i << "D" << "=" <<DxD[i]<<"  ";}}cout << endl;
	for(int i=1;i<13;i++) {if(DxG[i]){cout << BOLDGREEN << "D" << i << "G" << "=" <<DxG[i]<< RESET <<"  ";} else {cout << "D" << i << "G" << "=" <<DxG[i]<<"  ";}}cout << endl;
	for(int i=1;i<11;i++) {if(CPx[i]){cout << BOLDGREEN << "CP" << i << "=" <<CPx[i]<< RESET <<"  ";} else {cout << "CP" << i << "=" <<CPx[i]<<"  ";}}cout << endl;
	for(int i=1;i<9;i++) {if(CPIx[i]){cout << BOLDGREEN << "CPI" << i << "=" <<CPIx[i]<< RESET <<"  ";} else {cout << "CPI" << i << "=" <<CPIx[i]<<"  ";}}cout << endl;
	cout << endl;
}

void Afficher_actionneurs(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[])
{
	cout <<"~~~~~~ ACTIONNEURS ~~~~~~"<<endl<<endl;
	for(int i=1;i<25;i++) {if(STx[i]){cout << BOLDBLUE << "ST" << i << "=" <<STx[i]<< RESET <<"  ";} else{cout << "ST" << i << "=" <<STx[i]<<"  ";}} cout << endl;
	for(int i=1;i<13;i++) {if(RxD[i]){cout << BOLDBLUE << "R" << i << "D" << "=" <<RxD[i]<< RESET <<"  ";} else{cout << "R" << i << "D" << "=" <<RxD[i]<<"  ";}} cout << endl;
	for(int i=1;i<13;i++) {if(RxG[i]){cout << BOLDBLUE << "R" << i << "G" << "=" <<RxG[i]<< RESET <<"  ";} else{cout << "R" << i << "G" << "=" <<RxG[i]<<"  ";}} cout << endl;
	for(int i=1;i<13;i++) {if(Vx[i]){cout << BOLDBLUE << "V" << i << "=" <<Vx[i]<< RESET <<"  ";} else{cout << "V" << i << "=" <<Vx[i]<<"  ";}} cout << endl;
	for(int i=1;i<13;i++) {if(Dx[i]){cout << BOLDBLUE << "D" << i << "=" <<Dx[i]<< RESET <<"  ";} else{cout << "D" << i << "=" <<Dx[i]<<"  ";}} cout << endl;
	for(int i=1;i<9;i++) {if(PIx[i]){cout << BOLDBLUE << "PI" << i << "=" <<PIx[i]<< RESET <<"  ";} else{cout << "PI" << i << "=" <<PIx[i]<<"  ";}} cout << endl;
	cout<<endl;
	cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  " <<endl<<endl;
}

void Afficher_marquage_RdP(int M[],int nombre_places)
{
	cout <<"~~~~~~ Marquage RdP ~~~~~"<<endl<<endl;
	for(int i=1;i<=nombre_places;i++) {if(M[i]){cout << BOLDYELLOW << "M[" << i << "]=" <<M[i]<< RESET <<"  ";} else {cout << "M[" << i << "]=" <<M[i]<<"  ";}}
	cout << endl << endl;
}

void Deplacer_navettes(Actionneurs Actionneurs,bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[],int numero_stop)
{
	cout << "---> Déplacement des navettes ..." << endl<< endl;
	for(int i=0;i<25;i++) STx[i]=0;
	for(int i=0;i<13;i++) Dx[i]=1;
	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);
	Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);
	usleep(1000000);
	
	switch(numero_stop)
	{
		case 1 : 	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 2 : 	RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;	
		case 3 :	RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 4 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 5 :	RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 6 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 7 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;	
		case 8 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 9 :	RxG[1]=1;RxG[2]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 10 :	RxG[1]=1;RxG[2]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 11 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 12 :	RxG[1]=1;RxG[2]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 13 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 14 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 15 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 16 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 17 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 18 :	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 19 : 	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 20 : 	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 21 : 	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[12]=1; break;
		case 22 : 	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[12]=1; break;
		case 23 : 	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[11]=1;RxG[12]=1; break;
		case 24 : 	RxG[1]=1;RxG[2]=1;RxG[5]=1;RxG[6]=1;RxG[7]=1;RxG[8]=1;RxG[12]=1; break;
	}
	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);
	Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);
	usleep(4000000);

	for(int i=0;i<13;i++) Dx[i]=0;
	for(int i=0;i<13;i++) Vx[i]=1;

	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);
	Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);

	for(int i=0;i<25;i++) STx[i]=1;
	STx[numero_stop]=0;
	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);
	Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);
	usleep(40000000);

	for(int i=0;i<25;i++) STx[i]=0;
	for(int i=0;i<13;i++) RxD[i]=0;
	for(int i=0;i<13;i++) RxG[i]=0;
	for(int i=0;i<13;i++) Vx[i]=0;
	for(int i=0;i<13;i++) Dx[i]=0;
	for(int i=0;i<9;i++) PIx[i]=0;

	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);
	Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);
}

void Mode_ligne(Actionneurs Actionneurs,bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[])
{
	Dx[1]=1;Dx[2]=1;Dx[3]=1;Dx[10]=1;Dx[11]=1;Dx[12]=1;
	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);
	usleep(500000);

	RxD[1]=1;RxD[2]=1;RxG[3]=1;RxG[10]=1;RxD[11]=1;RxD[12]=1;
	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);
	usleep(4000000);

	Dx[1]=0;Dx[2]=0;Dx[3]=0;Dx[10]=0;Dx[11]=0;Dx[12]=0;
	Vx[1]=1;Vx[2]=1;Vx[3]=1;Vx[10]=1;Vx[11]=1;Vx[12]=1;

	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);
	usleep(500000);

	RxD[1]=0;RxD[2]=0;RxG[3]=0;RxG[10]=0;RxD[11]=0;RxD[12]=0;
	Vx[1]=1;Vx[2]=1;Vx[3]=1;Vx[10]=1;Vx[11]=1;Vx[12]=1;STx[6]=1;
	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);	
	usleep(500000);
}

void Deplacer_navettes_2(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[],Actionneurs Actionneurs,int numero_premier_stop,int numero_deuxieme_stop)
{
	cout << "---> Déplacement des navettes ..." << endl<< endl;
	
	for(int i=0;i<25;i++) STx[i]=1; 
	STx[numero_premier_stop]=0;STx[numero_deuxieme_stop]=0;  

	Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);
	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);

	usleep(15000000);
	
	for(int i=0;i<25;i++) STx[i]=0;
	Actionneurs.Envoyer(STx,RxD,RxG,Vx,Dx,PIx);
	Afficher_actionneurs(STx,RxD,RxG,Vx,Dx,PIx);
	
	usleep(1000000);
}








