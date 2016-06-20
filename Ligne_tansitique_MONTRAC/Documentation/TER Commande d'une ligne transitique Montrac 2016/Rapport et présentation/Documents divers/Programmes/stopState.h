/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/


#ifndef STOP_STATE
#define STOP_STATE
#include <ros/ros.h>
#include "commande_locale/Msg_StopControl.h"

class stopState
{
private:
	ros::Publisher stopStatePublisher;
	commande_locale::Msg_StopControl stateStop;
public:

	stopState ();
	void stop(int numStop);
	void go(int numStop);
	void publish();
	void init(ros::NodeHandle n);
};

#endif
