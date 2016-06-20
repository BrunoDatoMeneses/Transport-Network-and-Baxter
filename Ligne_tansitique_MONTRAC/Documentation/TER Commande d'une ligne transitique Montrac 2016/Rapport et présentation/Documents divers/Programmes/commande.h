#ifndef COMMANDE_SIMU
#define COMMANDE_SIMU

#include <ros/ros.h>
#include "actionneurs.h"


void Initialisation(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[],bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[]);

void Deplacer_navettes(Actionneurs Actionneurs,bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[],int numero_stop);
void Mode_ligne(Actionneurs Actionneurs,bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[]);

void Afficher_capteurs(bool PSx[],bool DxD[],bool DxG[],bool CPx[],bool CPIx[]);
void Afficher_actionneurs(bool STx[],bool RxD[],bool RxG[],bool Vx[],bool Dx[],bool PIx[]);
void Afficher_marquage_RdP(int M[],int nombre_places);



#endif
