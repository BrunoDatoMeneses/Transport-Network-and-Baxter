# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "commande_baxter: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/jade/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(commande_baxter_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv" NAME_WE)
add_custom_target(_commande_baxter_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "commande_baxter" "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv" "std_msgs/Empty"
)

#
#  langs = gencpp;geneus;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(commande_baxter
  "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Empty.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_baxter
)

### Generating Module File
_generate_module_cpp(commande_baxter
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_baxter
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(commande_baxter_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(commande_baxter_generate_messages commande_baxter_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv" NAME_WE)
add_dependencies(commande_baxter_generate_messages_cpp _commande_baxter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_baxter_gencpp)
add_dependencies(commande_baxter_gencpp commande_baxter_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_baxter_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(commande_baxter
  "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Empty.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_baxter
)

### Generating Module File
_generate_module_eus(commande_baxter
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_baxter
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(commande_baxter_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(commande_baxter_generate_messages commande_baxter_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv" NAME_WE)
add_dependencies(commande_baxter_generate_messages_eus _commande_baxter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_baxter_geneus)
add_dependencies(commande_baxter_geneus commande_baxter_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_baxter_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(commande_baxter
  "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Empty.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_baxter
)

### Generating Module File
_generate_module_lisp(commande_baxter
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_baxter
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(commande_baxter_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(commande_baxter_generate_messages commande_baxter_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv" NAME_WE)
add_dependencies(commande_baxter_generate_messages_lisp _commande_baxter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_baxter_genlisp)
add_dependencies(commande_baxter_genlisp commande_baxter_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_baxter_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(commande_baxter
  "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/std_msgs/cmake/../msg/Empty.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_baxter
)

### Generating Module File
_generate_module_py(commande_baxter
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_baxter
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(commande_baxter_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(commande_baxter_generate_messages commande_baxter_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Baxter/ros_ws/src/commande_baxter/srv/bool_state.srv" NAME_WE)
add_dependencies(commande_baxter_generate_messages_py _commande_baxter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_baxter_genpy)
add_dependencies(commande_baxter_genpy commande_baxter_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_baxter_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_baxter)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande_baxter
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(commande_baxter_generate_messages_cpp std_msgs_generate_messages_cpp)

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_baxter)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande_baxter
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
add_dependencies(commande_baxter_generate_messages_eus std_msgs_generate_messages_eus)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_baxter)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande_baxter
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(commande_baxter_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_baxter)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_baxter\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande_baxter
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(commande_baxter_generate_messages_py std_msgs_generate_messages_py)
