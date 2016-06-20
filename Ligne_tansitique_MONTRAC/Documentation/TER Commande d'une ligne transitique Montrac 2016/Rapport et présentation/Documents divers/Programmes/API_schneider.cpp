#include "API_schneider.h"
#include <ros/ros.h>
#include <modbus/modbus.h>
#include <iostream>
#include "automates/Entrees.h"
#include "automates/Sorties.h"

#define ADRESSE_ENTREES 1
#define ADRESSE_SORTIES 0
#define NOMBRE_REGISTRES 1

// Constructeur
API_schneider::API_schneider(ros::NodeHandle noeud,const std::string num_API,const char* adresse_ip_api)
{
	// Publishers
	pub_entrees = noeud.advertise<automates::Entrees>("/automates/Entrees_ap"+num_API, 1);

	// Subscriber
	sub_sorties = noeud.subscribe("/automates/Sorties_ap"+num_API, 1, &API_schneider::Callback,this);

	// Adresse IP
	adresse_ip = adresse_ip_api;

	// Inialisation entrees et sorties
	entrees = 0;
	sorties = 0;
}

// Destructeur
API_schneider::~API_schneider()
{
}

// Retourne un registre de la memoire partagee d'un automate
uint16_t API_schneider::get_register(int adresse_registre, int nombre_registres)
{
	modbus_t *ap;
	ap = modbus_new_tcp(adresse_ip,502);
	uint16_t registre;

	// Ouverture de la liaison Modbus avec l'automate
	modbus_connect(ap);

    // lecture du registre
	if (modbus_read_registers(ap,adresse_registre,nombre_registres,&registre) > 0)
	{
		//ROS_INFO("Lecture reussie !");
	}
	else ROS_INFO("Erreur lecture");

	// Fermeture liaison
	modbus_close(ap);
	modbus_free(ap);

	return registre;
}

// Ecriture dans un registre de la memoire partagee de l'automate
void API_schneider::write_register(int adresse_registre, int nombre_registres,uint16_t registre)
{
	modbus_t *ap;
	ap = modbus_new_tcp(adresse_ip,502);

	// Ouverture de la liaison Modbus avec l'automate
	modbus_connect(ap);

	// Ecriture sur un registre
	if (modbus_write_registers(ap,adresse_registre,nombre_registres,&registre) > 0)
	{
		//ROS_INFO("Ecriture reussie !");
	}
	else ROS_INFO("Erreur ecriture");

	// Fermeture liaison
	modbus_close(ap);
	modbus_free(ap);
}

// Ecriture des sorties de l'automate a la reception d'un message Sorties
void API_schneider::Callback(const automates::Sorties msg)
{
	ROS_INFO("API [%s] Sorties : %d",adresse_ip,msg.sorties);
	sorties=msg.sorties;
	write_register(ADRESSE_SORTIES,NOMBRE_REGISTRES,sorties);
}


// Publication des entrees de l'automate
void API_schneider::publish()
{
	automates::Entrees msg;
	entrees=get_register(ADRESSE_ENTREES,NOMBRE_REGISTRES);
	msg.entrees=entrees;
	pub_entrees.publish(msg);
}


//uint16_t MASK(uint16_t registre,int voie)
//{
//	return (registre & (uint16_t)pow(2,voie))/pow(2,voie);
//}







