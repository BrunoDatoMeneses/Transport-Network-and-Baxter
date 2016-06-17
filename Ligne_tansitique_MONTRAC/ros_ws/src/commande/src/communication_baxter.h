#ifndef BAXT
#define BAXT

#include <ros/ros.h>
#include "std_msgs/Bool.h"


class Communication_Baxter
{
private:

	//Publishers
	ros::Publisher pub_prise_demandee_bras_droit , pub_prise_demandee_bras_gauche ;

	//Subscribers
	ros::Subscriber sub_prise_effectuee_bras_droit , sub_prise_effectuee_bras_gauche ;

public:
	
	std_msgs::Bool msg_prise_demandee_bras_droit ,msg_prise_demandee_bras_gauche ;
	std_msgs::Bool msg_prise_effectuee_bras_droit,msg_prise_effectuee_bras_gauche ;
	
	Communication_Baxter(ros::NodeHandle noeud);
	~Communication_Baxter();

	void Callback_prise_effectuee_bras_droit(const std_msgs::Bool& msg);
	void Callback_prise_effectuee_bras_gauche(const std_msgs::Bool& msg);

	bool Prise_effectuee_bras_droit();
	bool Prise_effectuee_bras_gauche();

	void Prise_demandee_bras_droit();
	void Prise_demandee_bras_gauche();


	void Update();


};





#endif
