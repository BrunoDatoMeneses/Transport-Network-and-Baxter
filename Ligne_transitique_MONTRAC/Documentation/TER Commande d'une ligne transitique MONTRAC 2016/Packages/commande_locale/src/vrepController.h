/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/

#ifndef VREP_CONTROLLER
#define VREP_CONTROLLER

#include <ros/ros.h>
#include "vrep_common/simRosLoadModel.h"

#include "vrep_common/simRosPauseSimulation.h"
#include "vrep_common/simRosStartSimulation.h"
class vrepController
{
	private:
		ros::ServiceClient client_simRosLoadModel;
		vrep_common::simRosLoadModel srv_LoadModel;

		ros::ServiceClient client_simRosStartSimulation;
		vrep_common::simRosStartSimulation srv_StartSimulation;	

		ros::ServiceClient client_simRosPauseSimulation;
		vrep_common::simRosPauseSimulation srv_PauseSimulation;
	public:
		void init(ros::NodeHandle n);
		void close();
		void loadModel(char shuttleNumber);
		void waitVrep();
		void play();
		void pause();
};

#endif
