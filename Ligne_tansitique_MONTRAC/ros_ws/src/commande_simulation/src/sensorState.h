/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/


#ifndef SENSOR_STATE
#define SENSOR_STATE

#include <commande_locale/Msg_SensorState.h>
#include <ros/ros.h>

class sensorState
{
private:
	ros::Subscriber subSensorState;
public:
	int PS[17],CPI[9],CP[11], DD[13], DG[13];
	sensorState();
	void init(ros::NodeHandle n);
	void SensorCallback(const commande_locale::Msg_SensorState::ConstPtr& msg);
};

#endif
