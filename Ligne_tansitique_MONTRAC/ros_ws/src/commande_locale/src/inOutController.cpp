/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* * 
*/

#include "inOutController.h"

#include <ros/ros.h>

// Used API services:
#include "vrep_common/simRosEnablePublisher.h"
#include "vrep_common/simRosEnableSubscriber.h"

#include <commande_locale/Msg_SwitchControl.h>
#include <commande_locale/Msg_StopControl.h>
#include <commande_locale/Msg_SensorState.h>
#include <std_msgs/Int32.h>

// inOutController doit pouvoir actualiser l'UI à chaque actualisation de capteurs
inOutController::inOutController(UI* usrInt)
{
	userInterface = usrInt;
}

// Fonction Callback pour les capteurs sur les rails
void inOutController::SensorCallbackRail(const std_msgs::Int32::ConstPtr& msg)
{
	for(int i=1;i<=16;i++) SensorState.PS[i] = (msg->data & (int32_t)pow(2,i-1)) > 0;
	for(int i=1;i<=10;i++) SensorState.CP[i] = (msg->data & (int32_t)pow(2,15+i)) > 0;
	userInterface->DrawRailSensorImg(SensorState);
	planifRailSensorState.publish(SensorState);
}

// Fonction Callback pour les capteurs sur les aiguillages
void inOutController::SensorCallbackSwitch(const std_msgs::Int32::ConstPtr& msg)
{
	for(int i=1;i<=12;i++){
		SensorState.DD[i] = (msg->data & (int32_t)pow(2,2*i-2)) > 0;
		SensorState.DG[i] = (msg->data & (int32_t)pow(2,2*i-1)) > 0;
	}
	userInterface->DrawSwitchSensorImg(SensorState);
	planifRailSensorState.publish(SensorState);
}

// Fonction Callback pour les capteurs sur les stations de travail
void inOutController::SensorCallbackStation(const std_msgs::Int32::ConstPtr& msg)
{
	for(int i=1;i<=8;i++) SensorState.CPI[i] = (msg->data & (int32_t)pow(2,i-1)) > 0;
	userInterface->DrawStationSensorImg(SensorState);
	planifRailSensorState.publish(SensorState);
}

// Fonction Callback pour les actionneurs sur les aiguillages
void inOutController::StateSwitchCallBack(const commande_locale::Msg_SwitchControl::ConstPtr&  msg)
{
	int SwitchRightControl(0), SwitchLeftControl(0), SwitchLockControl(0);
	std_msgs::Int32 Right, Left, Lock;

	SwitchControl.RD = msg->RD;
	SwitchControl.RG = msg->RG;
	SwitchControl.LOCK = msg->LOCK;

	for (int i=1;i<=12;i++){
		if (msg->RD[i]==true)
			SwitchRightControl+=pow(2,i-1);
		if (msg->RG[i]==true)
			SwitchLeftControl+=pow(2,i-1);
		if (msg->LOCK[i]==true)
			SwitchLockControl+=pow(2,i-1);
	}

	Right.data=SwitchRightControl;
	VREPSwitchControllerRight.publish(Right);
	Left.data=SwitchLeftControl;
	VREPSwitchControllerLeft.publish(Left);
	Lock.data=SwitchLockControl;
	VREPSwitchControllerLock.publish(Lock);
}

// Fonction Callback pour les actionneurs sur les stops
void inOutController::StateStopCallBack(const commande_locale::Msg_StopControl::ConstPtr&  msg)
{
	int StopControlInt(0), GoControlInt(0);
	std_msgs::Int32 Stop, Go;

	StopControl.STOP = msg->STOP;
	StopControl.GO = msg->GO;

	for (int i=1;i<=24;i++){
		if (msg->STOP[i]==true)
			StopControlInt+=pow(2,i-1);
		if (msg->GO[i]==true)
			GoControlInt+=pow(2,i-1);
	}

	Stop.data=StopControlInt;
	VREPStopController.publish(Stop);
	Go.data=GoControlInt;
	VREPGoController.publish(Go);
}

// On s'abonne aux topic de VREP et du noeud Planificateur + On se prepare à publier sur les topic de la commande_locale
void inOutController::init(ros::NodeHandle nh)
{
	// Subscribe
   	VREPsubRailSensor = nh.subscribe("vrep/RailSensor", 1, &inOutController::SensorCallbackRail, this);
	VREPsubStationSensor = nh.subscribe("vrep/StationSensor", 1, &inOutController::SensorCallbackStation, this);
	VREPsubSwitchSensor = nh.subscribe("vrep/SwitchSensor", 1, &inOutController::SensorCallbackSwitch, this);
	planifSubSwitchState = nh.subscribe("/commande/Simulation/Actionneurs_aiguillages", 1, &inOutController::StateSwitchCallBack, this);
	planifSubStopState = nh.subscribe("/commande/Simulation/Actionneurs_stops", 1, &inOutController::StateStopCallBack, this);

	// Publishers
	VREPSwitchControllerRight = nh.advertise<std_msgs::Int32>("/commande_locale/SwitchControllerRight", 1);
	VREPSwitchControllerLeft = nh.advertise<std_msgs::Int32>("/commande_locale/SwitchControllerLeft", 1);
	VREPSwitchControllerLock = nh.advertise<std_msgs::Int32>("/commande_locale/SwitchControllerLock", 1);
	VREPStopController = nh.advertise<std_msgs::Int32>("/commande_locale/StopController", 1);
	VREPGoController = nh.advertise<std_msgs::Int32>("/commande_locale/GoController", 1);
	planifRailSensorState = nh.advertise<commande_locale::Msg_SensorState>("/commande/Simulation/Capteurs", 1);
}
