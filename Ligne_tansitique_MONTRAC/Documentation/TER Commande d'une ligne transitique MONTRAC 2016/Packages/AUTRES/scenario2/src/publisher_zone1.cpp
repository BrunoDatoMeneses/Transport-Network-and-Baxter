#include "ros/ros.h"
#include <sstream>

// On inclue le message et la librairie
#include "scenario1/EntreesSorties.h"
#include <modbus/modbus.h>

// On définie l'adresse des cases registre ENTREES et registre SORTIES dans l'automate 

#define ADRESSE_ENTREES 1
#define ADRESSE_SORTIES 0
#define NOMBRE_REGISTRES 1

uint16_t MASK(uint16_t registre,int voie);

int main(int argc, char **argv)
{
	// On initialise et déclare le noeud
	ros::init(argc, argv, "publisher_zone1");
	ros::NodeHandle n;

	// On abonne le noeud au topic "EntreesSorties" qui gère des messages de type "EntreesSorties" et on lui donne une fréquence de 1 Hz
	ros::Publisher chatter_pub = n.advertise<scenario1::EntreesSorties>("EntreesSorties", 1000);
	ros::Rate loop_rate(1);

	// On teste si le noeud est ouvert
	while (ros::ok())
	{

		// On déclare un message de type "EntreesSorties" et deux chaînes de caractères
		scenario1::EntreesSorties msg_entreessorties;
		std::stringstream entrees, sorties;

		// On déclare ce qui est utile pour Modbus : l'adresse de l'automate à joindre et des variables contenant l'état des postes
		modbus_t *ap1;
		int test=0;
		ap1 = modbus_new_tcp("192.168.0.101",502);
		uint16_t tab_entrees[NOMBRE_REGISTRES],tab_sorties[NOMBRE_REGISTRES];
    
		// On ouvre la liaison Modbus avec l'automate    
		test=modbus_connect(ap1);
		ROS_INFO("%d",test);


		// Si la fonction modbus_read_registers a fonctionné, on récupère les entrées et sorties de l'automate et on les stocke dans le message créé plus haut
		// On le fait pour les deux postes de travail

		
		ROS_INFO("~~~ ENTREES ~~~");
		ROS_INFO("%d",modbus_read_registers(ap1,ADRESSE_ENTREES,NOMBRE_REGISTRES,tab_entrees));
		fprintf(stderr, "%s\n", modbus_strerror(errno));


		if (modbus_read_registers(ap1,ADRESSE_ENTREES,NOMBRE_REGISTRES,tab_entrees) > 0) 
		{
			for(int i=0;i<=15;i++) ROS_INFO("Registre entrees, voie %d = %d",i,MASK(tab_entrees[0],i));
			msg_entreessorties.entrees = tab_entrees[0];
		}
		else ROS_INFO("Erreur lecture");
		ROS_INFO("------------------");	
		
		ROS_INFO("~~~ SORTIES ~~~");
		ROS_INFO("%d",modbus_read_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,tab_sorties));
		fprintf(stderr, "%s\n", modbus_strerror(errno));


		if (modbus_read_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,tab_sorties) > 0) 
		{
			for(int i=0;i<=15;i++) ROS_INFO("Registre sorties, voie %d = %d",i,MASK(tab_sorties[0],i));
			msg_entreessorties.sorties = tab_sorties[0];
		}
		else ROS_INFO("Erreur lecture");
		ROS_INFO("------------------");	
		
	
		// On ouvre la liaison Modbus avec l'automate
		modbus_close(ap1);
		modbus_free(ap1);

		// On publie le message contenant les registres d'entrées et de sorties 
    		chatter_pub.publish(msg_entreessorties);

		// On endort le publisher jusqu'au prochain passage dans la boucle (1 Hz)
   		loop_rate.sleep();
	}
 	return 0;
}

uint16_t MASK(uint16_t registre,int voie)
{
	return (registre & (uint16_t)pow(2,voie))/pow(2,voie);
}



