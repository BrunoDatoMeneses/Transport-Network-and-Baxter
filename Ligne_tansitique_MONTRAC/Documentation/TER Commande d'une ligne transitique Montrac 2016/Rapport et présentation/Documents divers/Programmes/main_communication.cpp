#include "communication_API_schneider.h"
#include "communication_commande.h"
#include <ros/ros.h>

using namespace std;

int main(int argc, char **argv)
{

	ros::init(argc, argv, "communication");
	ros::NodeHandle noeud;

    // Declaration des classes de communication avec les API et la commande
	Communication_API_schneider AP1(noeud,"1"),AP2(noeud,"2");
	Communication_commande Com(noeud);

    // Frequence de la boucle
	ros::Rate loop_rate(27);

	while (ros::ok()) // Tant que ROS est actif,
	{
		Com.Concatenation_entrees(AP1,AP2);

		// Publication du message Capteurs pour la commande
		Com.publish();

		Com.Decoupe_sorties(&AP1,&AP2);

        // Publication des sorties vers les automates
		AP1.publish();
		AP2.publish();

		ros::spinOnce(); // Activation des fonctions Callback si messages entrants

		loop_rate.sleep(); // Synchronisation sur la frequence de la boucle
	}

	return 0;
}
