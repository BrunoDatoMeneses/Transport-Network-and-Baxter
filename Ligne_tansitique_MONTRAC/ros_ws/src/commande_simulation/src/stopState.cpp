/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/


#include "stopState.h"
#include <commande_locale/Msg_StopControl.h>
//Msg_StopControl est un message qui comprend 2 mots de 32 bits STOP et GO, dont les 24 premiers bits sont significatifs et indiquent si ils sont actifs (1) ou non (0)
#include <ros/ros.h>


stopState::stopState () {
// Constructeur de la classe, et initialise tous les points d'arrêts 
	for(int i=1;i<=24;i++) stateStop.STOP[i] = 0;
	for(int i=1;i<=24;i++) stateStop.GO[i] = 1;
	
}

void stopState::stop(int numStop)
//fonction qui met le point d'arret "numStop" en mode stop
{
	stateStop.STOP[numStop] = 1;
	stateStop.GO[numStop] = 0;
	publish(); // appelle la fonction publish definie plus bas
}

void stopState::go(int numStop)
//fonction qui met le point d'arret "numStop" en mode continu
{
	stateStop.STOP[numStop] = 0;
	stateStop.GO[numStop] = 1;
	publish(); // appelle la fonction publish definie plus bas
}
void stopState::publish()
//fonction qui, lorsqu'elle est appelée, publie dans le canal de communication entre la couche basse et la couche haute les états voulus de Tous les points d'arrêts
{
	stopStatePublisher.publish(stateStop);
}

void stopState::init(ros::NodeHandle n)
// créé le canal de communication 'planifStopControl' entre la couche haute et la couche basse
{
	stopStatePublisher = n.advertise<commande_locale::Msg_StopControl>("/commande/Simulation/Actionneurs_stops", 1);
}


////// A chaque fois que l'utilisateur modifie un point d'arret (en stop ou en continu), leurs états sont automatiquement publiés et envoyés à la commande_locale.
