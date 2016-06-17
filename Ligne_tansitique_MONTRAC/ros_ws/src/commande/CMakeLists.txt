cmake_minimum_required(VERSION 2.8.3)
project(commande)

find_package(catkin REQUIRED)
find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	std_msgs 
	genmsg 
	message_generation)

add_message_files(FILES Capteurs.msg Actionneurs.msg)
generate_messages(DEPENDENCIES std_msgs)

include_directories(${catkin_INCLUDE_DIRS})
include_directories(include ${OpenCV_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH ../../../)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 



add_executable(run src/main_commande.cpp  src/commande.cpp src/capteurs.cpp src/actionneurs.cpp src/communication_baxter.cpp) 
target_link_libraries(run ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(run vrep_common_generate_messages_cpp)
