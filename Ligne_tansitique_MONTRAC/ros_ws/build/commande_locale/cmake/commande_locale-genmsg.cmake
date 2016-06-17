# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "commande_locale: 3 messages, 0 services")

set(MSG_I_FLAGS "-Icommande_locale:/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg;-Istd_msgs:/opt/ros/jade/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(commande_locale_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg" NAME_WE)
add_custom_target(_commande_locale_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "commande_locale" "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg" NAME_WE)
add_custom_target(_commande_locale_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "commande_locale" "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg" NAME_WE)
add_custom_target(_commande_locale_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "commande_locale" "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_locale
)
_generate_msg_cpp(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_locale
)
_generate_msg_cpp(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_locale
)

### Generating Services

### Generating Module File
_generate_module_cpp(commande_locale
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_locale
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(commande_locale_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(commande_locale_generate_messages commande_locale_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_cpp _commande_locale_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_cpp _commande_locale_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_cpp _commande_locale_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_locale_gencpp)
add_dependencies(commande_locale_gencpp commande_locale_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_locale_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_locale
)
_generate_msg_eus(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_locale
)
_generate_msg_eus(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_locale
)

### Generating Services

### Generating Module File
_generate_module_eus(commande_locale
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_locale
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(commande_locale_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(commande_locale_generate_messages commande_locale_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_eus _commande_locale_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_eus _commande_locale_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_eus _commande_locale_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_locale_geneus)
add_dependencies(commande_locale_geneus commande_locale_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_locale_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_locale
)
_generate_msg_lisp(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_locale
)
_generate_msg_lisp(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_locale
)

### Generating Services

### Generating Module File
_generate_module_lisp(commande_locale
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_locale
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(commande_locale_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(commande_locale_generate_messages commande_locale_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_lisp _commande_locale_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_lisp _commande_locale_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_lisp _commande_locale_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_locale_genlisp)
add_dependencies(commande_locale_genlisp commande_locale_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_locale_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_locale
)
_generate_msg_py(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_locale
)
_generate_msg_py(commande_locale
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_locale
)

### Generating Services

### Generating Module File
_generate_module_py(commande_locale
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_locale
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(commande_locale_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(commande_locale_generate_messages commande_locale_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SwitchControl.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_py _commande_locale_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_SensorState.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_py _commande_locale_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande_locale/msg/Msg_StopControl.msg" NAME_WE)
add_dependencies(commande_locale_generate_messages_py _commande_locale_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_locale_genpy)
add_dependencies(commande_locale_genpy commande_locale_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_locale_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_locale)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_locale
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(commande_locale_generate_messages_cpp std_msgs_generate_messages_cpp)

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_locale)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_locale
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
add_dependencies(commande_locale_generate_messages_eus std_msgs_generate_messages_eus)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_locale)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_locale
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(commande_locale_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_locale)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_locale\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_locale
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(commande_locale_generate_messages_py std_msgs_generate_messages_py)
