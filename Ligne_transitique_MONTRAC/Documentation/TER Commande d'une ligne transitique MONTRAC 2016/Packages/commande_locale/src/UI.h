/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/

#ifndef VAR_UI
#define VAR_UI

#include <ros/ros.h>

// Image Streaming
#include <image_transport/image_transport.h>
#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <cv_bridge/cv_bridge.h>

#include <commande_locale/Msg_SensorState.h>
#include "vrepController.h"

class UI
{
	private:
		vrepController* VREPController;

		cv::Mat imageSensor;
		cv::Mat imageSimu;
		cv::Mat imageTot;
		cv::Mat playButton;
		cv::Mat playButton_Down;
		cv::Mat playButton_On;
		cv::Mat pauseButton;
		cv::Mat pauseButton_Down;
		cv::Mat pauseButton_On;

		int mode;

		image_transport::Subscriber subImage;
	public:
		UI(vrepController* VREPContrl);
		void DrawRailSensorImg(commande_locale::Msg_SensorState SensorState);
		void DrawStationSensorImg(commande_locale::Msg_SensorState SensorState);
		void DrawSwitchSensorImg(commande_locale::Msg_SensorState SensorState);
		void init(ros::NodeHandle nh);
		void update();
		void getSimuStream(const sensor_msgs::ImageConstPtr& msg);
		void onMouse_internal( int event, int x, int y);
		friend void onMouse(int event, int x, int y, int, void* userdata);
		void close();
};

#endif
