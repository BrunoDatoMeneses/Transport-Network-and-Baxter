# TER M1 ISTR Université Paul Sabatier Toulouse France 2016

> Command of a transport network and it simulation

## Authors
- __Bruno DATO__ -- bruno.dato.meneses@gmail.com
- __Abdellah ELGOURAIN__ -- elgourain@gmail.com
- __Evgeny SHULGA__ -- hlebovod@mail.ru


# TO DO

## Install ROS 

1. **To install the latest version of ROS, go to http://wiki.ros.org/ROS/Installation and install the appropiate version for your platform**

## Install Modbus

2. **Open a terminal and write**

	-sudo apt-get install libmodbus-dev 


## Create the workspace


3. **In ~/ Create a folder named for example "Working_Folder_Montrac", it will contain your workspace**
	- In this folder, copy the folders *img* and *V-REP* and the file *Simulation.ttt* (you can find them in ~/.../Ligne_transitique_MONTRAC, every time you will find "/.../" you have to replace this by the path that leads to a folder or a file on YOUR computer)


4. **In ~/.bashrc, add these lines :**
	- source /opt/ros/*ROS_version*/setup.bash (source /opt/ros/jade/setup.bash for example if your installed ROS JADE)
	- export VREP_ROOT_DIR=~/ ... /Working_Folder_Montrac/V-Rep/

5. **Create the workspace ros_ws : in ~/.../Working_Folder_Montrac :**
	- $ mkdir -p ros_ws/src
	- $ cd ros_ws/src
	- $ catkin_init_workspace
	- $ cd ..
	- $ catkin_make

6. **In ~/.bashrc, add this line :**
	- source ~/ ... /Working_Folder_Montrac/ros_ws/devel/setup.bash (this line will avoid you to always write source devel/setup.bash every time you open a new terminal)
	- if you are using another ros workspace in parallel, don't add this line in ~/.bashrc, you will have to write the command "source devel/setup.bash" every time that you open a new terminal and that you are in /ros_ws

## Add the packages

7. **in ~/.../Working_Folder_Montrac/ros_ws/src**
	- copy the packages of ~/.../Ligne_transitique_MONTRAC/ros_ws/src (which are the folders *automates*, *commande*, *commande_locale*, *communication* and *vrep_common*)

8. **in the packages automates, commande, commande_locale and communication :**
	- open the file *CMakeLists.txt*, comment the lines 21, 22 and 23 using the character "#" and save (they correspond to the creation of the executable files)

9. **In ~/.../Working_Folder_Montrac/ros_ws/ :**
	- catkin_make

10. **Return to the file *CMakeLists.txt* of the package automates**
	- uncomment the lines 21, 22 and 23 and save
	- in ~/.../Working_Folder_Montrac/ros_ws/ :
	- $ catkin_make (a red line should appear which means that the executable have been created)
	- repeat this step for all the other packages that you have commented (commande, commande_locale and communication)




11.  **In a terminal, write the command "roscore" if you haven't done it yet to launch the local master**


## Run the simulation 


12. **If you are using the real transport network, ignore this step. To run the simulation, in a new terminal, in ~/ ... /Working_Folder_Montrac**

	- ./simulation 1 2 5 6 (or any number of shuttle between 1 and 6 seperated with a space)
	- if the simulation doesn't lauch successfully stop it by doing CTRL+C try a second time "$ ./simulation 1 2 5 6" before restarting all the steps



## Run the tranport network 


13. **If you are using the simulation, ignore this step. To run the real transport network**

	- Before executing the following programs, make sure that you have configured all the PLC (Programmable Logic Controller, API in french) using PL7 PRO (see README at ~/ ... /Ligne_transitique_MONTRAC/Documentation/TER Commande d'une ligne transitique MONTRAC 2016/PL7)
	- in a new terminal, in ~/ ... /Working_Folder_Montrac/ros_ws
	- $ rosrun automates connect
	- in a new terminal, still in ~/ ... /Working_Folder_Montrac/ros_ws 
	- $ rosrun communication start


## Run a command


14. **DO NOT MAKE THIS STEP IF BOTH THE SIMULATION AND THE REAL TRANSPORT NETWORK ARE RUNNING !!! In a new terminal, in ~/ ... /Working_Folder_Montrac/ros_ws**

	- $ rosrun commande run
	- This will run the command that is in ~/.../Workin_Folder/ros_ws/src/commande, you can choose the command you want to run in ~/ ... /Ligne_transitique_MONTRAC/Documentation/TER Commande d'une ligne transitique MONTRAC 2016/Commandes.

	- if your are using the simulation, once it is detected :  SIMULATION ON and LIGNE TRANSITIQUE OFF, press play on the simulation (try not to be too long)
	- it will take long to start the command, it's normal 

	- if your are using the real transport network, you have to put the shuttles on the tracks and power on them by connecting them to the tracks and turning on the yellow button on their right side.

	- if a shuttle is stuck on a stop, it is probably because of an error reading the value of a sensor, you can gently push the shuttle so it will continue its way. Don't wait too loog before pushing it because if it happends in a curve the others shuttles will bump in the stucked shuttle (the sensor proximity on each shuttle is not very efficient in the curves).


## MORE INFOS

**If you want to see the simulation.ttt on VREP :**
   - Execute ~/ ... /Ligne_transitique_MONTRAC/V-Rep/vrep.sh ~/CelluleFlexible/Simulation.ttt

**If you want more information about how to use ROS go to http://wiki.ros.org/fr/ROS/Tutorials**

## License

[![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)](http://creativecommons.org/publicdomain/zero/1.0/)
