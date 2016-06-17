/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/


#include "switchState.h"
#include <ros/ros.h>

#include "commande_locale/Msg_SwitchControl.h"
//Msg_StopControl est un message qui comprend 3 mots de 32 bits LOCK, RD (droite) et RG(gauche), dont les 12 premiers bits sont significatifs et indiquent si ils sont actifs (1) ou non (0), actif signifiant que l'utilisateur les force dans cet état (!!! LOCK[i] à 1 signifie que l'aiguillage i est verrouillé et que l'on ne peut pas le tourner)

switchState::switchState () 
// Constructeur de la classe, et initialise tous les aiguillages en mode verrouillé (les aiguillages commencent en position droite). 
{
	for(int i=1;i<=12;i++) stateSwitches.LOCK[i] = 0;
	for(int i=1;i<=12;i++) stateSwitches.RD[i] = 0;
	for(int i=1;i<=12;i++) stateSwitches.RG[i] = 0;
}

void switchState::init(ros::NodeHandle n)
// créé le canal de communication 'planifSwitchControl' entre la couche haute et la couche basse
{
	switchStatePublisher = n.advertise<commande_locale::Msg_SwitchControl>("/commande/Simulation/Actionneurs_aiguillages", 1);
}

void switchState::unlockSwitch(int numSwitch)
//fonction qui déverrouille l'aiguillage "numSwitch"
{
	stateSwitches.LOCK[numSwitch] = 1;
	publish();
}
void switchState::lockSwitch(int numSwitch)
//fonction qui verrouille l'aiguillage "numSwitch"
{
	stateSwitches.LOCK[numSwitch] = 0;
	stateSwitches.RD[numSwitch] = 0;
	stateSwitches.RG[numSwitch] = 0;
	publish();
}
void switchState::turnRight(int numSwitch)
//fonction qui tourne l'aiguillage "numSwitch" vers la droite (que si déverrouillé)
{
	stateSwitches.RG[numSwitch] = 0;
	stateSwitches.RD[numSwitch] = 1;
	publish();		
}
void switchState::turnLeft(int numSwitch)
//fonction qui tourne l'aiguillage "numSwitch" vers la gauche (que si déverrouillé)
{
	stateSwitches.RD[numSwitch] = 0;
	stateSwitches.RG[numSwitch] = 1;
	publish();		
}

void switchState::publish()
//fonction qui, lorsqu'elle est appelée, publie dans le canal de communication entre la couche basse et la couche haute les états voulus de Tous les aiguillages et leur verrouillage
{
	switchStatePublisher.publish(stateSwitches);
}
