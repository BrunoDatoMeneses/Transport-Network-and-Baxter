cmake_minimum_required(VERSION 2.8.3)
project(commande_locale)

find_package(catkin REQUIRED)
find_package(catkin REQUIRED COMPONENTS 
	std_msgs 
	sensor_msgs
	image_transport 
	vrep_common 
	cv_bridge 
	genmsg
	message_generation)
find_package(OpenCV)

include_directories(${catkin_INCLUDE_DIRS})
include_directories(include ${OpenCV_INCLUDE_DIRS})
set(EXECUTABLE_OUTPUT_PATH ../../../)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


add_executable(simulation src/commande_locale.cpp src/UI.cpp src/inOutController.cpp src/vrepController.cpp) 
target_link_libraries(simulation ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(simulation vrep_common_generate_messages_cpp)

add_message_files(
	FILES
	Msg_SensorState.msg
	Msg_StopControl.msg
	Msg_SwitchControl.msg
)
generate_messages( DEPENDENCIES std_msgs)
catkin_package( CATKIN_DEPENDS message_runtime) 
