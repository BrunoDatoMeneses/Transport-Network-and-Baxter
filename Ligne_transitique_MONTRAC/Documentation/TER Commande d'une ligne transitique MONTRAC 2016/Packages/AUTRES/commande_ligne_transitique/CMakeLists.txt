cmake_minimum_required(VERSION 2.8.3)
project(commande_ligne_transitique)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  genmsg
  message_generation
)

add_message_files(FILES Capteurs.msg Actionneurs.msg)

generate_messages(DEPENDENCIES std_msgs)


catkin_package(CATKIN_DEPENDS roscpp rospy std_msgs message_runtime)

include_directories(${catkin_INCLUDE_DIRS})
include_directories(include ${OpenCV_INCLUDE_DIRS})


add_executable(commande_ligne_transitique src/main_commande_ligne_transitique.cpp src/commande_ligne_transitique.cpp)

add_dependencies(commande_ligne_transitique commande_ligne_transitique_generate_messages_cpp)

target_link_libraries(commande_ligne_transitique ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
