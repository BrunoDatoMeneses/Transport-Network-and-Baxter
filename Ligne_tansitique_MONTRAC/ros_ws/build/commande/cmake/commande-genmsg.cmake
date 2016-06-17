# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "commande: 2 messages, 0 services")

set(MSG_I_FLAGS "-Icommande:/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg;-Istd_msgs:/opt/ros/jade/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(commande_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg" NAME_WE)
add_custom_target(_commande_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "commande" "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg" ""
)

get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg" NAME_WE)
add_custom_target(_commande_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "commande" "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(commande
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande
)
_generate_msg_cpp(commande
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande
)

### Generating Services

### Generating Module File
_generate_module_cpp(commande
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(commande_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(commande_generate_messages commande_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg" NAME_WE)
add_dependencies(commande_generate_messages_cpp _commande_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg" NAME_WE)
add_dependencies(commande_generate_messages_cpp _commande_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_gencpp)
add_dependencies(commande_gencpp commande_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(commande
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande
)
_generate_msg_eus(commande
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande
)

### Generating Services

### Generating Module File
_generate_module_eus(commande
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(commande_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(commande_generate_messages commande_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg" NAME_WE)
add_dependencies(commande_generate_messages_eus _commande_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg" NAME_WE)
add_dependencies(commande_generate_messages_eus _commande_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_geneus)
add_dependencies(commande_geneus commande_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(commande
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande
)
_generate_msg_lisp(commande
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande
)

### Generating Services

### Generating Module File
_generate_module_lisp(commande
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(commande_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(commande_generate_messages commande_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg" NAME_WE)
add_dependencies(commande_generate_messages_lisp _commande_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg" NAME_WE)
add_dependencies(commande_generate_messages_lisp _commande_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_genlisp)
add_dependencies(commande_genlisp commande_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(commande
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande
)
_generate_msg_py(commande
  "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande
)

### Generating Services

### Generating Module File
_generate_module_py(commande
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(commande_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(commande_generate_messages commande_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Actionneurs.msg" NAME_WE)
add_dependencies(commande_generate_messages_py _commande_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/etudiant/M1_ISTR/Ligne_tansitique_MONTRAC/ros_ws/src/commande/msg/Capteurs.msg" NAME_WE)
add_dependencies(commande_generate_messages_py _commande_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(commande_genpy)
add_dependencies(commande_genpy commande_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS commande_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/commande
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(commande_generate_messages_cpp std_msgs_generate_messages_cpp)

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/commande
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
add_dependencies(commande_generate_messages_eus std_msgs_generate_messages_eus)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/commande
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(commande_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/commande
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(commande_generate_messages_py std_msgs_generate_messages_py)
