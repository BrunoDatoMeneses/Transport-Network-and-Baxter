#include "ros/ros.h"
#include <sstream>
#include <stdio.h>

// On inclue le service et la librairie
#include "scenario1/Etat_API.h"
#include <modbus/modbus.h>

#define ADRESSE_ENTREES 1
#define ADRESSE_SORTIES 0
#define NOMBRE_REGISTRES 1
#define ADRESSE_IP_API_1 "192.168.0.101"
#define ADRESSE_IP_API_2 "192.168.0.102"
#define ADRESSE_IP_API_3 "192.168.0.103"
#define ADRESSE_IP_API_4 "192.168.0.104"
#define ADRESSE_IP_API_5 "192.168.0.105"

uint16_t MASK(uint16_t registre,int voie);

// On déclare la fonction "traitement" : ses paramètres son ceux du service DemandeTrajet
bool traitement(scenario1::Etat_API::Request  &req,
                scenario1::Etat_API::Response &res)
{
	// On déclare ce qui est utile pour Modbus 
	modbus_t *ap1;
	const char *adresse_ip="";
	
	switch (req.numero_API)
	{
		case 1:
		adresse_ip=ADRESSE_IP_API_1;
  		break;
		case 2:
		adresse_ip=ADRESSE_IP_API_2;
  		break;
		case 3:
		adresse_ip=ADRESSE_IP_API_3;
  		break;
		case 4:
		adresse_ip=ADRESSE_IP_API_4;
  		break;
		case 5:
		adresse_ip=ADRESSE_IP_API_5;
  		break;
	}

	ap1 = modbus_new_tcp(adresse_ip, 502);
	uint16_t tab_entrees[NOMBRE_REGISTRES],tab_sorties[NOMBRE_REGISTRES];

	// On ouvre la liaison Modbus avec l'automate    
	modbus_connect(ap1);

	ROS_INFO("~~~ ENTREES ~~~");
	if (modbus_read_registers(ap1,ADRESSE_ENTREES,NOMBRE_REGISTRES,tab_entrees) > 0) 
	{
		for(int i=0;i<=15;i++) ROS_INFO("Registre entrees, voie %d = %d",i,MASK(tab_entrees[0],i));
		res.entrees = tab_entrees[0];
	}
	else ROS_INFO("Erreur lecture entrees");
	ROS_INFO("------------------");	

	ROS_INFO("~~~ SORTIES ~~~");
	if (modbus_read_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,tab_sorties) > 0) 
	{
		for(int i=0;i<=15;i++) ROS_INFO("Registre sorties, voie %d = %d",i,MASK(tab_sorties[0],i));
		res.sorties = tab_sorties[0];
	}
	else ROS_INFO("Erreur lecture sorties");
	ROS_INFO("------------------");	

	// On ouvre la liaison Modbus avec l'automate
	modbus_close(ap1);
	modbus_free(ap1);

	return TRUE;
}


int main(int argc, char **argv)
{
  // On initialise et déclare le noeud
  ros::init(argc, argv, "service_etat_API");
  ros::NodeHandle n;

  // On abonne le noeud au service "etat_API" et indique que la fonction "traitement" sera appelée à chaque demande
  ros::ServiceServer service = n.advertiseService("etat_API", traitement);

  ROS_INFO("Ready to send data from APIs...");

  // On rentre dans un boucle
  ros::spin();

  return 0;
}




uint16_t MASK(uint16_t registre,int voie)
{
	return (registre & (uint16_t)pow(2,voie))/pow(2,voie);
}