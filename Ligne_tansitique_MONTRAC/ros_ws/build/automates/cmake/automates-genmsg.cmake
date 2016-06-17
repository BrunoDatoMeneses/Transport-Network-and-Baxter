# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "automates: 2 messages, 0 services")

set(MSG_I_FLAGS "-Iautomates:/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg;-Istd_msgs:/opt/ros/jade/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(automates_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg" NAME_WE)
add_custom_target(_automates_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "automates" "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg" ""
)

get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg" NAME_WE)
add_custom_target(_automates_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "automates" "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(automates
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automates
)
_generate_msg_cpp(automates
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automates
)

### Generating Services

### Generating Module File
_generate_module_cpp(automates
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automates
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(automates_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(automates_generate_messages automates_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg" NAME_WE)
add_dependencies(automates_generate_messages_cpp _automates_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg" NAME_WE)
add_dependencies(automates_generate_messages_cpp _automates_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(automates_gencpp)
add_dependencies(automates_gencpp automates_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS automates_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(automates
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automates
)
_generate_msg_eus(automates
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automates
)

### Generating Services

### Generating Module File
_generate_module_eus(automates
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automates
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(automates_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(automates_generate_messages automates_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg" NAME_WE)
add_dependencies(automates_generate_messages_eus _automates_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg" NAME_WE)
add_dependencies(automates_generate_messages_eus _automates_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(automates_geneus)
add_dependencies(automates_geneus automates_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS automates_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(automates
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automates
)
_generate_msg_lisp(automates
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automates
)

### Generating Services

### Generating Module File
_generate_module_lisp(automates
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automates
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(automates_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(automates_generate_messages automates_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg" NAME_WE)
add_dependencies(automates_generate_messages_lisp _automates_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg" NAME_WE)
add_dependencies(automates_generate_messages_lisp _automates_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(automates_genlisp)
add_dependencies(automates_genlisp automates_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS automates_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(automates
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automates
)
_generate_msg_py(automates
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automates
)

### Generating Services

### Generating Module File
_generate_module_py(automates
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automates
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(automates_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(automates_generate_messages automates_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Sorties.msg" NAME_WE)
add_dependencies(automates_generate_messages_py _automates_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/automates/msg/Entrees.msg" NAME_WE)
add_dependencies(automates_generate_messages_py _automates_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(automates_genpy)
add_dependencies(automates_genpy automates_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS automates_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automates)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automates
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(automates_generate_messages_cpp std_msgs_generate_messages_cpp)

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automates)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automates
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
add_dependencies(automates_generate_messages_eus std_msgs_generate_messages_eus)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automates)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automates
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(automates_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automates)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automates\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automates
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(automates_generate_messages_py std_msgs_generate_messages_py)
