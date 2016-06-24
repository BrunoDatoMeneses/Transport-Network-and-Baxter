/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/


#include "UI.h"
#include "vrepController.h"

// Image Streaming
#include <image_transport/image_transport.h>
#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <cv_bridge/cv_bridge.h>

#include <commande_locale/Msg_SensorState.h>

// l'UI doit pouvoir controller la simu (Play & Pause)
UI::UI(vrepController* VREPContrl)
{
	VREPController = VREPContrl;
}

/* On actualise les aiguillages (On dessine des cercles gris, sur lequel 
on rajoute une droite ou un arc de cercle pour afficher l'etat de l'aiguillage) */
void UI::DrawSwitchSensorImg(commande_locale::Msg_SensorState SensorState)
{
	circle(imageSensor, cv::Point(21, 241), 17, cv::Scalar(200,200,200), -1); //A01
	circle(imageSensor, cv::Point(270, 252), 17, cv::Scalar(200,200,200), -1); //A02
	circle(imageSensor, cv::Point(378, 235), 17, cv::Scalar(200,200,200), -1); //A03
	circle(imageSensor, cv::Point(642, 235), 17, cv::Scalar(200,200,200), -1); //A04
	circle(imageSensor, cv::Point(751, 252), 17, cv::Scalar(200,200,200), -1); //A05
	circle(imageSensor, cv::Point(1002, 240), 17, cv::Scalar(200,200,200), -1); //A06
	circle(imageSensor, cv::Point(1000, 126), 17, cv::Scalar(200,200,200), -1); //A07
	circle(imageSensor, cv::Point(752, 111), 17, cv::Scalar(200,200,200), -1); //A08
	circle(imageSensor, cv::Point(645, 126), 17, cv::Scalar(200,200,200), -1); //A09
	circle(imageSensor, cv::Point(377, 129), 17, cv::Scalar(200,200,200), -1); //A10
	circle(imageSensor, cv::Point(269, 112), 17, cv::Scalar(200,200,200), -1); //A11
	circle(imageSensor, cv::Point(22, 125), 17, cv::Scalar(200,200,200), -1); //A12

	if(SensorState.DD[1]) line(imageSensor, cv::Point(14, 227), cv::Point(14, 255), cv::Scalar(0,100,0), 3); //A01
	if(SensorState.DG[1]) ellipse(imageSensor, cv::Point(37, 220),cv::Size(23,23),0,92,163,cv::Scalar(0,100,0), 3);
	if(SensorState.DD[2]) ellipse(imageSensor, cv::Point(290, 268),cv::Size(23,23),0,183,255,cv::Scalar(0,100,0), 3);//A02
	if(SensorState.DG[2]) line(imageSensor, cv::Point(257, 245), cv::Point(283, 245), cv::Scalar(0,100,0), 3);
	if(SensorState.DD[3]) line(imageSensor, cv::Point(365, 243), cv::Point(391, 243), cv::Scalar(0,100,0), 3); //A03
	if(SensorState.DG[3]) ellipse(imageSensor, cv::Point(358, 221),cv::Size(23,23),0,73,1,cv::Scalar(0,100,0), 3);
	if(SensorState.DD[4]) line(imageSensor, cv::Point(629, 243), cv::Point(655, 243), cv::Scalar(0,100,0), 3); //A04
	if(SensorState.DG[4]) ellipse(imageSensor, cv::Point(665, 220),cv::Size(23,23),0,113,181,cv::Scalar(0,100,0), 3);
	if(SensorState.DD[5]) ellipse(imageSensor, cv::Point(732, 265),cv::Size(23,23),0,284,363,cv::Scalar(0,100,0), 3);//A05
	if(SensorState.DG[5]) line(imageSensor, cv::Point(738, 245), cv::Point(764, 245), cv::Scalar(0,100,0), 3); 
	if(SensorState.DD[6]) line(imageSensor, cv::Point(1008, 226), cv::Point(1008, 253), cv::Scalar(0,100,0), 3); //A06
	if(SensorState.DG[6]) ellipse(imageSensor, cv::Point(985, 221),cv::Size(23,23),0,83,12,cv::Scalar(0,100,0), 3);
	if(SensorState.DD[7]) line(imageSensor, cv::Point(1008, 113), cv::Point(1008, 139), cv::Scalar(0,100,0), 3); //A07
	if(SensorState.DG[7]) ellipse(imageSensor, cv::Point(985, 145),cv::Size(23,23),0,271,348,cv::Scalar(0,100,0), 3);
	if(SensorState.DD[8]) ellipse(imageSensor, cv::Point(733, 96),cv::Size(23,23),0,75,3,cv::Scalar(0,100,0), 3);//A08
	if(SensorState.DG[8]) line(imageSensor, cv::Point(740, 121), cv::Point(764, 121), cv::Scalar(0,100,0), 3); 
	if(SensorState.DD[9]) line(imageSensor, cv::Point(631, 121), cv::Point(659, 121), cv::Scalar(0,100,0), 3); //A09
	if(SensorState.DG[9]) ellipse(imageSensor, cv::Point(665, 143),cv::Size(23,23),0,184,256,cv::Scalar(0,100,0), 3);
	if(SensorState.DD[10]) line(imageSensor, cv::Point(363, 122), cv::Point(390, 122), cv::Scalar(0,100,0), 3); //A10
	if(SensorState.DG[10]) ellipse(imageSensor, cv::Point(358, 144),cv::Size(23,23),0,282,357,cv::Scalar(0,100,0), 3);
	if(SensorState.DD[11]) ellipse(imageSensor, cv::Point(290, 98),cv::Size(23,23),0,110,183,cv::Scalar(0,100,0), 3); //A11
	if(SensorState.DG[11]) line(imageSensor, cv::Point(257, 121), cv::Point(281, 121), cv::Scalar(0,100,0), 3);
	if(SensorState.DD[12]) line(imageSensor, cv::Point(14, 112), cv::Point(14, 138), cv::Scalar(0,100,0), 3); //A12
	if(SensorState.DG[12]) ellipse(imageSensor, cv::Point(38, 145),cv::Size(23,23),0,194,268,cv::Scalar(0,100,0), 3);

	update();
}

// On actualise l'etat des capteurs des stations de travail (cercle rouge ou vert)
void UI::DrawStationSensorImg(commande_locale::Msg_SensorState SensorState)
{
	circle(imageSensor, cv::Point(100, 346), 5, cv::Scalar(0,255*SensorState.CPI[1],255-255*SensorState.CPI[1]), -1, 8 );
	circle(imageSensor, cv::Point(185, 346), 5, cv::Scalar(0,255*SensorState.CPI[2],255-255*SensorState.CPI[2]), -1, 8 );
  	circle(imageSensor, cv::Point(847, 345), 5, cv::Scalar(0,255*SensorState.CPI[3],255-255*SensorState.CPI[3]), -1, 8 );
	circle(imageSensor, cv::Point(931, 345), 5, cv::Scalar(0,255*SensorState.CPI[4],255-255*SensorState.CPI[4]), -1, 8 );
	circle(imageSensor, cv::Point(925, 21), 5, cv::Scalar(0,255*SensorState.CPI[5],255-255*SensorState.CPI[5]), -1, 8 );
	circle(imageSensor, cv::Point(841, 22), 5, cv::Scalar(0,255*SensorState.CPI[6],255-255*SensorState.CPI[6]), -1, 8 );
	circle(imageSensor, cv::Point(183, 19), 5, cv::Scalar(0,255*SensorState.CPI[7],255-255*SensorState.CPI[7]), -1, 8 );
	circle(imageSensor, cv::Point(97, 20), 5, cv::Scalar(0,255*SensorState.CPI[8],255-255*SensorState.CPI[8]), -1, 8 );

	update();
}

// On actualise l'etat des capteurs des rails (cercle rouge ou vert)
void UI::DrawRailSensorImg(commande_locale::Msg_SensorState SensorState)
{
	circle(imageSensor, cv::Point(45, 349), 5, cv::Scalar(0,255*SensorState.CP[1],255-255*SensorState.CP[1]), -1, 8 );
	circle(imageSensor, cv::Point(122, 231), 5, cv::Scalar(0,255*SensorState.CP[2],255-255*SensorState.CP[2]), -1, 8 );
  	circle(imageSensor, cv::Point(447, 231), 5, cv::Scalar(0,255*SensorState.CP[3],255-255*SensorState.CP[3]), -1, 8 );
	circle(imageSensor, cv::Point(788, 348), 5, cv::Scalar(0,255*SensorState.CP[4],255-255*SensorState.CP[4]), -1, 8 );
	circle(imageSensor, cv::Point(806, 230), 5, cv::Scalar(0,255*SensorState.CP[5],255-255*SensorState.CP[5]), -1, 8 );
	circle(imageSensor, cv::Point(981, 18), 5, cv::Scalar(0,255*SensorState.CP[6],255-255*SensorState.CP[6]), -1, 8 );
	circle(imageSensor, cv::Point(878, 135), 5, cv::Scalar(0,255*SensorState.CP[7],255-255*SensorState.CP[7]), -1, 8 );
	circle(imageSensor, cv::Point(576, 135), 5, cv::Scalar(0,255*SensorState.CP[8],255-255*SensorState.CP[8]), -1, 8 );
	circle(imageSensor, cv::Point(236, 16), 5, cv::Scalar(0,255*SensorState.CP[9],255-255*SensorState.CP[9]), -1, 8 );
	circle(imageSensor, cv::Point(190, 135), 5, cv::Scalar(0,255*SensorState.CP[10],255-255*SensorState.CP[10]), -1, 8 );

	circle(imageSensor, cv::Point(27, 181), 5, cv::Scalar(0,255*SensorState.PS[1],255-255*SensorState.PS[1]), -1, 8 );
	circle(imageSensor, cv::Point(241, 230), 5, cv::Scalar(0,255*SensorState.PS[2],255-255*SensorState.PS[2]), -1, 8 );
	circle(imageSensor, cv::Point(248, 342), 5, cv::Scalar(0,255*SensorState.PS[3],255-255*SensorState.PS[3]), -1, 8 );
	circle(imageSensor, cv::Point(326, 230), 5, cv::Scalar(0,255*SensorState.PS[4],255-255*SensorState.PS[4]), -1, 8 );
	circle(imageSensor, cv::Point(572, 231), 5, cv::Scalar(0,255*SensorState.PS[5],255-255*SensorState.PS[5]), -1, 8 );
	circle(imageSensor, cv::Point(700, 231), 5, cv::Scalar(0,255*SensorState.PS[6],255-255*SensorState.PS[6]), -1, 8 );
	circle(imageSensor, cv::Point(934, 232), 5, cv::Scalar(0,255*SensorState.PS[7],255-255*SensorState.PS[7]), -1, 8 );
	circle(imageSensor, cv::Point(992, 339), 5, cv::Scalar(0,255*SensorState.PS[8],255-255*SensorState.PS[8]), -1, 8 );
	circle(imageSensor, cv::Point(995, 189),5, cv::Scalar(0,255*SensorState.PS[9],255-255*SensorState.PS[9]), -1, 8 );
	circle(imageSensor, cv::Point(783, 135), 5, cv::Scalar(0,255*SensorState.PS[10],255-255*SensorState.PS[10]), -1, 8 );
	circle(imageSensor, cv::Point(770, 28), 5, cv::Scalar(0,255*SensorState.PS[11],255-255*SensorState.PS[11]), -1, 8 );
	circle(imageSensor, cv::Point(701, 136), 5, cv::Scalar(0,255*SensorState.PS[12],255-255*SensorState.PS[12]), -1, 8 );
	circle(imageSensor, cv::Point(454, 135), 5, cv::Scalar(0,255*SensorState.PS[13],255-255*SensorState.PS[13]), -1, 8 );
	circle(imageSensor, cv::Point(321, 135), 5, cv::Scalar(0,255*SensorState.PS[14],255-255*SensorState.PS[14]), -1, 8 );
	circle(imageSensor, cv::Point(66, 135), 5, cv::Scalar(0,255*SensorState.PS[15],255-255*SensorState.PS[15]), -1, 8 );
	circle(imageSensor, cv::Point(29, 26), 5, cv::Scalar(0,255*SensorState.PS[16],255-255*SensorState.PS[16]), -1, 8 );

    	update();
}

// On intègre le stream de la simu et l'états des capteurs et aiguillage dans l'UI
void UI::update()
{
	imageSimu.copyTo(imageTot.rowRange(18,530).colRange(78,1102));
 	imageSensor.copyTo(imageTot.rowRange(570,936).colRange(78,1102));
			
 	cv::imshow("Simulation", imageTot);
}

// Fonction Callback du Stream de la simu
void UI::getSimuStream(const sensor_msgs::ImageConstPtr& msg)
{
	imageSimu = cv_bridge::toCvShare(msg, "bgr8")->image;
	update();
}

// Fonction callback des infos sur la souris
void onMouse(int event, int x, int y, int, void* userdata)
{
    UI* ui = static_cast<UI*>(userdata);
    ui->onMouse_internal(event, x, y);
}

/* Fonction appellée pour mettre Play ou Pause à la simu 
et changer l'etat des boutons, en fonction de la position de la souris */
void UI::onMouse_internal( int event, int x, int y)
{
	static vrep_common::simRosStartSimulation srv_StartSimulation;		
	static vrep_common::simRosPauseSimulation srv_PauseSimulation;

	switch(event) {
		case cv::EVENT_LBUTTONDOWN :
   			if(y>545 && y < 570 && x>453 && x<563 && mode!= 1) {
					playButton_Down.copyTo(imageTot.rowRange(545,570).colRange(453,563));
					pauseButton.copyTo(imageTot.rowRange(545,570).colRange(617,727));
					VREPController->play();
					mode = 1; }
    		else if(y>545 && y < 570 && x>617 && x<727 && mode !=0) {
					playButton.copyTo(imageTot.rowRange(545,570).colRange(453,563));
					pauseButton_Down.copyTo(imageTot.rowRange(545,570).colRange(617,727));
					VREPController->pause();
					mode = 0; }
		break;
		case cv::EVENT_MOUSEMOVE :
   			if(y>545 && y < 570 && x>453 && x<563 && mode!= 1)
					playButton_On.copyTo(imageTot.rowRange(545,570).colRange(453,563));
				else if (mode!= 1)
					playButton.copyTo(imageTot.rowRange(545,570).colRange(453,563));
    		if(y>545 && y < 570 && x>617 && x<727 && mode !=0)
					pauseButton_On.copyTo(imageTot.rowRange(545,570).colRange(617,727));
				else if (mode!= 0)
					pauseButton.copyTo(imageTot.rowRange(545,570).colRange(617,727));
		break;
	}
}


void UI::init(ros::NodeHandle nh){
	imageSensor = cv::imread("img/Schema_cellule.png",CV_LOAD_IMAGE_COLOR);
	imageSimu = cv::Mat::zeros(512, 1024, CV_8UC3 );
	imageTot = cv::Mat::zeros(950, 1180, CV_8UC3 );
	imageTot.setTo(cv::Scalar(200,200,200));

	playButton = cv::imread("img/PlayButton.png",CV_LOAD_IMAGE_COLOR);
	playButton_Down = cv::imread("img/PlayButton_Down.png",CV_LOAD_IMAGE_COLOR);
	playButton_On = cv::imread("img/PlayButton_On.png",CV_LOAD_IMAGE_COLOR);

	pauseButton = cv::imread("img/PauseButton.png",CV_LOAD_IMAGE_COLOR);
	pauseButton_Down = cv::imread("img/PauseButton_Down.png",CV_LOAD_IMAGE_COLOR);
	pauseButton_On = cv::imread("img/PauseButton_On.png",CV_LOAD_IMAGE_COLOR);

	rectangle(imageTot, cv::Point(75,15), cv::Point(1105,533),cv::Scalar(100,100,100),2);
	playButton.copyTo(imageTot.rowRange(545,570).colRange(453,563));
	pauseButton_Down.copyTo(imageTot.rowRange(545,570).colRange(617,727));

	// Window
	cv::namedWindow("Simulation");
	cv::startWindowThread();
	cv::moveWindow("Simulation",0,0);
	cv::setMouseCallback("Simulation", onMouse,this);

	// Subscribe
	image_transport::ImageTransport it(nh);
	subImage = it.subscribe("vrep/VisionSensorData", 1, &UI::getSimuStream, this);

	mode = 0; // Mode 0 : Pause - Mode 1 : Play
}

// On ferme la fenetre de Simulation
void UI::close(){
	cv::destroyWindow("Simulation");
}
