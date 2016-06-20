#include "ros/ros.h"
#include <sstream>

// On inclue le message et la librairie
#include "scenario1/EntreesSorties.h"
#include <modbus/modbus.h>
#include <unistd.h>

// On définie l'adresse des cases registre ENTREES et registre SORTIES dans l'automate 


#define ADRESSE_ENTREES 1
#define ADRESSE_SORTIES 0
#define NOMBRE_REGISTRES 1


uint16_t MASK(uint16_t registre,int voie);
uint16_t CMD(uint16_t registre_actuel,int voie,int action);

int main(int argc, char **argv)
{
	// On initialise et déclare le noeud
	ros::init(argc, argv, "test_aiguillage");
	ros::NodeHandle n;

	// On abonne le noeud au topic "EntreesSorties" qui gère des messages de type "EntreesSorties" et on lui donne une fréquence de 1 Hz
	//ros::Publisher chatter_pub = n.advertise<scenario1::EntreesSorties>("test_aiguillage", 1000);
	ros::Rate loop_rate(0.03);

	// On teste si le noeud est ouvert
	while (ros::ok())
	{
		// On déclare ce qui est utile pour Modbus : l'adresse de l'automate à joindre et des variables contenant l'état des postes
		modbus_t *ap1;
		ap1 = modbus_new_tcp("192.168.0.101", 502);
		uint16_t registe_actionneurs,request;
		
		// On ouvre la liaison Modbus avec l'automate    
		modbus_connect(ap1);

		//Lire registre sorties
		if (modbus_read_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&registe_actionneurs) > 0)
		{
			ROS_INFO("Registre sorties =%d",registe_actionneurs);
		}

		usleep(2000000);
		
		//MAZ Registre
		request = 0;	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("MAZ - ACK");			
		else ROS_INFO("MAZ - ERR"); 

		usleep(2000000);
		
		//Lecture reg
		if (modbus_read_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&registe_actionneurs) > 0)
		{
			ROS_INFO("Registre sorties =%d",registe_actionneurs);
		}

		usleep(2000000);
		
		//Dévérouiller D11 à 1
		request = CMD(registe_actionneurs,3,1);	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("D11 MAU - ACK");			
		else ROS_INFO("D11 - ERR");  

		usleep(2000000);
		
		//Actionner R11d à 1
		request = CMD(registe_actionneurs,0,1);	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("R11d MAU - ACK");			
		else ROS_INFO("R11d - ERR");

		usleep(2000000);

		//MAZ Registre
		request = 0;	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("MAZ - ACK");			
		else ROS_INFO("MAZ - ERR"); 

		usleep(2000000); 

		//Actionner R11g à 1
		request = CMD(registe_actionneurs,1,1);	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("R11g MAU - ACK");			
		else ROS_INFO("R11g - ERR");

		usleep(2000000);

		//MAZ Registre
		request = 0;	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("MAZ - ACK");			
		else ROS_INFO("MAZ - ERR"); 

		usleep(200000); 

		//Actionner R11d à 1
		request = CMD(registe_actionneurs,0,1);	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("R11d MAU - ACK");			
		else ROS_INFO("R11d - ERR");

		usleep(2000000);


		//Actionner R11g à 1
		request = CMD(registe_actionneurs,1,1);	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("R11g MAU - ACK");			
		else ROS_INFO("R11g - ERR");

		usleep(2000000);

		//MAZ Registre
		request = 0;	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("MAZ - ACK");			
		else ROS_INFO("MAZ - ERR"); 

		usleep(200000);

		//Vérouiller V11 à 1
		request = CMD(registe_actionneurs,2,1);	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("V11 MAU - ACK");			
		else ROS_INFO("V11 - ERR");

		usleep(2000000); 

		//MAZ Registre
		request = 0;	
		if (modbus_write_registers(ap1,ADRESSE_SORTIES,NOMBRE_REGISTRES,&request)) ROS_INFO("MAZ - ACK");			
		else ROS_INFO("MAZ - ERR"); 

		 
	
			
	
		// On ouvre la liaison Modbus avec l'automate
		modbus_close(ap1);
		modbus_free(ap1);


		// On endort le publisher jusqu'au prochain passage dans la boucle (1 Hz)
   		loop_rate.sleep();
		

	}
 	return 0;
}


uint16_t MASK(uint16_t registre,int voie)
{
	return (registre & (uint16_t)pow(2,voie))/pow(2,voie);
}

uint16_t CMD(uint16_t registre_actuel,int voie,int action)
{
	if((action==0) && (MASK(registre_actuel,voie)==1)) return (registre_actuel - ((uint16_t)pow(2,voie)));	
	else if((action==1) && (MASK(registre_actuel,voie)==0)) return (registre_actuel + ((uint16_t)pow(2,voie)));
	else 
	{
		ROS_INFO("COMMANDE IMPOSSIBLE");
		return registre_actuel;
	}


}












