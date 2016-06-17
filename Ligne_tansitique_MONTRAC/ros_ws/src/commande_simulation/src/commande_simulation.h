#ifndef COMMANDE_SIMU
#define COMMANDE_SIMU



#include "sensorState.h"
#include "switchState.h"
#include "stopState.h"
#include <ros/ros.h>


void Initialisation(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[],bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[]);
void Actualiser_Capteurs(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[],sensorState SensorSt);
void Actualiser_Actionneurs(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[],stopState *stopSt,switchState *switchSt);

void Afficher_capteurs(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[]);
void Afficher_actionneurs(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[]);
void Afficher_marquage_RdP(int M[],int nombre_places);

void Deplacer_navettes(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[],stopState *stopSt,switchState *switchSt,int numero_premier_stop,int numero_deuxieme_stop);

void left(switchState* switchSt,int num);
void right(switchState* switchSt,int num);
void stop(stopState* stopSt,int num);
void go(stopState* stopSt,int num);


#endif
