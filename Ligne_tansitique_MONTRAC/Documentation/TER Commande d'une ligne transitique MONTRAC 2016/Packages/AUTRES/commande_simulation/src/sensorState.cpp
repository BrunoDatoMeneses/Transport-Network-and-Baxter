/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/


#include "sensorState.h"
#include <ros/ros.h>

#include <commande_locale/Msg_SensorState.h>
//Msg_SensorState est un message qui comprend 5 mots de 32 bits PS[i], CP[i], CPI[i], DG[i] et DD[i] qui indiquent si le capteur i est actif (1) ou non (0).



void sensorState::SensorCallback(const commande_locale::Msg_SensorState::ConstPtr& msg)
// cette fonction est appellée en boucle et met à jour les états de tous les capteurs 
{
	for(int i=1;i<=16;i++) PS[i] = msg->PS[i];
	for(int i=1;i<=10;i++) CP[i] = msg->CP[i];
	for(int i=1;i<=8;i++) CPI[i] = msg->CPI[i];
	for(int i=1;i<=12;i++) DG[i] = msg->DG[i];
	for(int i=1;i<=12;i++) DD[i] = msg->DD[i];
}

sensorState::sensorState () {
// Constructeur de la classe, il créé les places pour tous les capteurs. 
	for(int i=1;i<=16;i++) PS[i] = 0;
	for(int i=1;i<=10;i++) CP[i] = 0;
	for(int i=1;i<=8;i++) CPI[i] = 0;
	for(int i=1;i<=12;i++) DG[i] = 0;
	for(int i=1;i<=12;i++) DD[i] = 0;
}
void sensorState::init(ros::NodeHandle n)
// Fonction qui s'abonne au canal qui donne les états des capteurs venant de la couche basse.
{
	subSensorState = n.subscribe("/commande/Simulation/Capteurs", 1, &sensorState::SensorCallback,this);
}
