/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/


#ifndef SWITCH_STATE
#define SWITCH_STATE
#include <ros/ros.h>
#include "commande_locale/Msg_SwitchControl.h"

class switchState
{
private:
	ros::Publisher switchStatePublisher;
	commande_locale::Msg_SwitchControl stateSwitches;
public:

	switchState ();
	void unlockSwitch(int numSwitch);
	void lockSwitch(int numSwitch);
	void turnRight(int numSwitch);
	void turnLeft(int numSwitch);
	void publish();
	void init(ros::NodeHandle n);
};

#endif
