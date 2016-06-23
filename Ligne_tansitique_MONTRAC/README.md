# TER M1 ISTR Université Paul Sabatier Toulouse France 2016

> Command of a transport network and it simulation

## Authors
- __Bruno DATO__ -- bruno.dato.meneses@gmail.com
- __Abdellah ELGOURAIN__ -- elgourain@gmail.com
- __Evgeny SHULGA__ -- hlebovod@mail.ru


# TO DO

## Install ROS 

1. **To install the latest version of ROS, go to http://wiki.ros.org/ROS/Installation and install the appropiate version for your platform**


## Create the workspace


2. **In ~/ Create a folder named for example "Folder", it will contain your workspace**
	- in this folder, copy the folders *img* and *V-REP* and the file *Simulation.ttt* (you can find them in ~/.../Ligne_transitique_MONTRAC)


3. **In ~/.bashrc, add these lines :**
	- source /opt/ros/*ROS_version*/setup.bash (source /opt/ros/jade/setup.bash for example if your installed ROS JADE)
	- export VREP_ROOT_DIR=~/ ... /Folder/V-Rep/

4. **Create the workspace ros_ws : in ~/.../Folder :**
	- $ mkdir -p ros_ws/src
	- $ cd ros_ws/src
	- $ catkin_init_workspace
	- $ cd ..
	- $ catkin_make
	- $ source devel/setup.bash

## Add the packages

5. **in ~/.../Folder/ros_ws/src**
	- copy the packages of ~/.../Ligne_transitique_MONTRAC/ros_ws/src (which are the folders *automates*, *commande*, *commande_locale*, *communication* and *vrep_common*)

6. **in the packages automates, commande, commande_locale and communication :**
	- open the file *CMakeLists.txt*, comment the lines 21, 22 and 23 using the character "#" and save

7. **In ~/.../Folder/ros_ws/ :**
	- $ source devel/setup.bash (if you opened a new terminal)
	- catkin_make

8. **Return to the file *CMakeLists.txt* of the package automates**
	- uncomment the lines 21, 22 and 23 and save
	- in ~/.../Folder/ros_ws/ :
	- $ source devel/setup.bash (if you opened a new terminal)
	- catkin_make (a red line should appear which means that the executable have been created)
	- repeat this step for all the other packages that you have commented (commande, commande_locale and communication)




4. **In ~/ ... /Ligne_transitique_MONTRAC/ros_ws**
	- source devel/setup.bash
	- catkin_make


## Run the simulation

5. **Don't forget to launch roscore before launching any application**
	- ~/ ... /Ligne_transitique_MONTRAC/simulation 1 2 5 6 (or any number of shuttle between 1 and 6 seperated with a space)


## Run the tranport network



## Run a command


## MORE INFOS

**If you want to see the simulation.ttt on VREP :**
   - Execute ~/ ... /Ligne_transitique_MONTRAC/V-Rep/vrep.sh ~/CelluleFlexible/Simulation.ttt

## License

[![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)](http://creativecommons.org/publicdomain/zero/1.0/)
