# STAGE M1 ISTR Université Paul Sabatier Toulouse France 2016

> Command of the robot Baxter and the transport network.
> Baxter's arms, 3 shuttles.
> Description : each time a shuttle arrives at the stop number 22, one of Baxter's arms will take a virtual object and put it away, the arm which is available at the moment.

## Author

- __Bruno DATO__ -- bruno.dato.meneses@gmail.com


## TO DO

1. **In ~/ ... /Working_Folder_MONTRAC/ros_ws/src/commande/src :**

	- replace the file *main_commande.cpp* by *main_commande baxter 2 bras ligne transitique.cpp*
	- rename *main_commande baxter 2 bras ligne transitique.cpp* by *main_commande.cpp*

2. **In ~/ ... /Working_Folder_Baxter/ros_ws/src/commande/src :**

	- replace the file *main_commande.cpp* by *main_commande_baxter.cpp*
	- rename *main_commande_baxter.cpp* by *main_commande.cpp*


3. **Don't launch roscore this time, you will use the master of Baxter which is always running once he is turned on**


4. **In a new terminal (CTRL+SHIFT+T), in ~/ ... /Working_Folder_MONTRAC/ros_ws**

	- $ source devel/setup.bash	(only the first time you open the terminal)
	- $ catkin_make

5. **In a new terminal (CTRL+SHIFT+T), in ~/ ... /Working_Folder_Baxter/ros_ws**

	- $ source devel/setup.bash	(only the first time you open the terminal)
	- $ catkin_make



## IF YOU USE THE SIMULATION

6. **To run the simulation using Baxter's master, in a new terminal, in ~/ ... /Working_Folder_MONTRAC**

	- $ ROS_MASTER_URI=http://baxter.local:11311	(to define the master which is Baxter's, only the first time you open the terminal)
	- $ ./simulation  2 4 6		(we use 3 shuttles for this command)
	- if the simulation doesn't lauch successfully stop it by doing CTRL+C try a second time "$ ./simulation 2 4 6" before restarting all the steps


## IF YOU USE THE REAL TRANSPORT NETWORK

7. **To run the real transport network using Baxter's master**

	- Before executing the following programs, make sure that you have configured all the PLC (Programmable Logic Controller, API in french) using PL7 PRO (see README at ~/ ... /Ligne_transitique_MONTRAC/Documentation/TER Commande d'une ligne transitique MONTRAC 2016/PL7)

	- in a new terminal, in ~/ ... /Working_Folder_MONTRAC/ros_ws
	- $ ROS_MASTER_URI=http://baxter.local:11311	(to define the master which is Baxter's, only the first time you open the terminal)
	- $ source devel/setup.bash	(only the first time you open the terminal)
	- $ rosrun automate connect

	- in a new terminal, still in ~/ ... /Working_Folder_MONTRAC/ros_ws 
	- $ ROS_MASTER_URI=http://baxter.local:11311	(to define the master which is Baxter's, only the first time you open the terminal)
	- $ source devel/setup.bash	(only the first time you open the terminal)
	- $ rosrun communication start


## ONCE THE SIMULATION OR THE REAL TRANPORT NETWORK IS RUNNING

8. **To run Baxter**

	- in a new terminal, in ~/ ... /Working_Folder_Baxter/ros_ws
	- $ ROS_MASTER_URI=http://baxter.local:11311	(to define the master which is Baxter's, only the first time you open the terminal)
	- $ source devel/setup.bash	(only the first time you open the terminal)
	- $ rosrun baxter run

	

9. **DO NOT MAKE THIS STEP IF BOTH THE SIMULATION AND THE REAL TRANSPORT NETWORK ARE RUNNING !!! In a new terminal, in ~/ ... /Working_Folder_MONTRAC/ros_ws**

	- $ source devel/setup.bash	(only the first time you open the terminal)
	- $ ROS_MASTER_URI=http://baxter.local:11311	(to define the master which is Baxter's, only the first time you open the terminal)
	- $ rosrun commande run

	- if your are using the simulation, once it is detected :  SIMULATION ON and LIGNE TRANSITIQUE OFF, press play on the simulation (try not to be too long)
	- it will take long to start the command, it's normal 
	- if the shuttles don't stop at the initilization point, change the position *5* by *4* in the fonction *Deplacer_navettes(Actionneurs,STx,RxD,RxG,Vx,Dx,PIx,24)* line 101, save and restart from step 3.

	- if your are using the real transport network, you have to put on the tracks the 2 shuttles before the stop number 4 and power them on by connecting them to the tracks and turning on the yellow button on their right side.

	- if a shuttle is stuck on a stop, it is probably because of an error reading the value of a sensor, you can gently push the shuttle so it will continue its way. Don't wait too loog before pushing it because if it happends in a curve the others shuttles will bump in the stucked shuttle (the sensor proximity on each shuttle is not very efficient in the curves).


## License

[![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)](http://creativecommons.org/publicdomain/zero/1.0/)
