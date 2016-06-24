cmake_minimum_required(VERSION 2.8.3)
project(commande_simulation)

find_package(catkin REQUIRED)
find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	std_msgs 
	genmsg 
	message_generation)
include_directories(${catkin_INCLUDE_DIRS})
include_directories(include ${OpenCV_INCLUDE_DIRS})
set(EXECUTABLE_OUTPUT_PATH ../../../)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_executable(commande_simulation src/main_commande_simulation.cpp src/sensorState.cpp src/switchState.cpp src/stopState.cpp src/commande_simulation.cpp) 
target_link_libraries(commande_simulation ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(commande_simulation vrep_common_generate_messages_cpp)
