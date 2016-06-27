cmake_minimum_required(VERSION 2.8.3)
project(tests_baxter)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  xacro
  actionlib
  sensor_msgs
  control_msgs
  trajectory_msgs
  cv_bridge
  dynamic_reconfigure
  baxter_core_msgs
  baxter_interface
)



catkin_package(
  CATKIN_DEPENDS
  rospy
  roscpp
  xacro
  actionlib
  sensor_msgs
  control_msgs
  trajectory_msgs
  cv_bridge
  dynamic_reconfigure
  baxter_core_msgs
  baxter_interface
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)




add_executable(wave src/main_commande_test.cpp src/baxter_left_arm.cpp src/baxter_right_arm.cpp src/baxter.cpp)
target_link_libraries(wave ${catkin_LIBRARIES})
add_dependencies(wave commande_baxter_generate_messages_cpp)

add_executable(states src/listener.cpp)
target_link_libraries(states ${catkin_LIBRARIES})
add_dependencies(states commande_baxter_generate_messages_cpp)









