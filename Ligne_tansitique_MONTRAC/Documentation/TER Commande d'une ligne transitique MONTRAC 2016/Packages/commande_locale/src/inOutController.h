/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     * 
 * ********************************* *
*/


#ifndef IN_OUT_CONTROLLER
#define IN_OUT_CONTROLLER

#include "UI.h"
#include <ros/ros.h>
#include "commande_locale/Msg_SwitchControl.h"
#include "commande_locale/Msg_StopControl.h"
#include "commande_locale/Msg_SensorState.h"

#include <std_msgs/Int32.h>

class inOutController
{
private:
	UI* userInterface;
	ros::Publisher VREPSwitchControllerRight;
	ros::Publisher VREPSwitchControllerLeft;
	ros::Publisher VREPSwitchControllerLock;
	ros::Publisher VREPStopController;
	ros::Publisher VREPGoController;
	ros::Publisher planifRailSensorState;
	ros::Subscriber subSensorState;
	ros::Subscriber VREPsubRailSensor;
	ros::Subscriber VREPsubStationSensor;
	ros::Subscriber VREPsubSwitchSensor;
	ros::Subscriber planifSubSwitchState;
	ros::Subscriber planifSubStopState;

	commande_locale::Msg_StopControl StopControl;
	commande_locale::Msg_SwitchControl SwitchControl;
	commande_locale::Msg_SensorState SensorState;
public:
	inOutController(UI* usrInt);
	void init(ros::NodeHandle nh);
	// Sensors
	void SensorCallbackRail(const std_msgs::Int32::ConstPtr& msg);
	void SensorCallbackSwitch(const std_msgs::Int32::ConstPtr& msg);
	void SensorCallbackStation(const std_msgs::Int32::ConstPtr& msg);
	// Actuators
	void StateSwitchCallBack(const commande_locale::Msg_SwitchControl::ConstPtr&  msg);
	void StateStopCallBack(const commande_locale::Msg_StopControl::ConstPtr&  msg);
};
#endif
