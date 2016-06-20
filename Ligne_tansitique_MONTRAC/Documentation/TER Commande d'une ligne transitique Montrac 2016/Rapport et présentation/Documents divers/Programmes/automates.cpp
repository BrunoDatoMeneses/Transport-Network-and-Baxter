#include "API_schneider.h"
#include <ros/ros.h>

#define ADRESSE_IP_API1 "192.168.0.101"
#define ADRESSE_IP_API2 "192.168.0.102"
#define ADRESSE_IP_API3 "192.168.0.103"
#define ADRESSE_IP_API4 "192.168.0.104"
#define ADRESSE_IP_API5 "192.168.0.105"

int main(int argc, char **argv)
{

	ros::init(argc, argv, "automates");
	ros::NodeHandle noeud;

    // Declaration des 2 automates
	API_schneider AP1(noeud,"1",ADRESSE_IP_API1),AP2(noeud,"2",ADRESSE_IP_API2);

    // Frequence d'execution de la boulce
	ros::Rate loop_rate(30);

	while (ros::ok()) // Tant que ROS est actif
	{
	    // Publication des entrees des automates
		AP1.publish();
		AP2.publish();

        // activation de la fonction Callback si reception de messages
		ros::spinOnce();

        // synchronisation sur la frequence choisie
		loop_rate.sleep();
	}

	return 0;
}
