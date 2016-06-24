# Stage M1 ISTR Université Paul Sabatier Toulouse France 2016

> Command of the robot Baxter interacting with a transport network

## Author
- __Bruno DATO__ -- bruno.dato.meneses@gmail.com


# TO DO

## Install ROS 

1. **To install the latest version of ROS, go to http://wiki.ros.org/ROS/Installation and install the appropiate version for your platform**


## Create the workspace


2. **In ~/ Create a folder named for example "Working_Folder_Baxter", it will contain your workspace**
	

3. **In ~/.bashrc, add these lines :**
	- source /opt/ros/*ROS_version*/setup.bash (source /opt/ros/jade/setup.bash for example if your installed ROS JADE)


4. **Create the workspace ros_ws : in ~/.../Working_Folder_Baxter :**
	- $ mkdir -p ros_ws/src
	- $ cd ros_ws/src
	- $ catkin_init_workspace
	- $ cd ..
	- $ catkin_make
	- $ catkin_make install
	- $ source devel/setup.bash


## Install Baxter Research Robot SDK


5. **Install wstool :**
	- $ sudo apt-get install python-wstool

6. **Install Baxter SDK, in ~/.../Working_Folder_Baxter :**
	- cd ros_ws/src
	- $ wstool init .
	- $ wstool merge https://raw.githubusercontent.com/RethinkRobotics/baxter/master/baxter_sdk.rosinstall
	- $ wstool update

7. **Build and install :**
	- $ cd ..
	- $ catkin_make
	- $ catkin_make install


## Configure Baxter Communication


8. **Download the baxter.sh script, in ~/.../Working_Folder_Baxter/ros_ws :**
	- $ wget https://github.com/RethinkRobotics/baxter/raw/master/baxter.sh
	- $ chmod u+x baxter.sh

9. **Customize the baxter.sh script**
	- $ gedit baxter.sh
	- Specify Baxter's hostname line 22 : baxter_hostname="baxter.local"
	- Specify your IP adress line 26 : your_ip="192.168.XXX.XXX" 
	- you can use the command "ifconfig" to identify your IP adress
	- Specify your ROS version line 30 : ros_version="XXXX"
	- Save and close


## Add the packages

10. **In ~/.../Working_Folder_Baxter/ros_ws/src :**
	- Copy the folders *commande_baxter* and *tests_baxter* (you can find them in ~/.../Baxter/Documentation/Packages)
	- In ~/.../Working_Folder_Baxter/ros_ws
	- $ source devel/setup.bash (if you opened a new terminal)
	- $ catkin_make (you should see 2 red lines for the 2 executables created)
	- $ catkin_make install


## Test the communication

11. **Initialize your SDK environment, in ~/.../Working_Folder_Baxter/ros_ws :**
	- $ . baxter.sh
	- $ source devel/setup.bash (if you opened a new terminal)
	- $ env | grep ROS (to check that your workspace is correctly initialized)
	- $ rosrun tests_baxter wave (if the robot moves, the communication is well established) 
	- CTRL+C to stop


## Run a command


12. **In the same terminal, in ~/.../Working_Folder_Baxter/ros_ws :**
	- $ rosrun commande_baxter run


## MORE INFOS

**If you want more information about how to use ROS go to http://wiki.ros.org/fr/ROS/Tutorials**

**If you want more information about how to use Baxter go to http://sdk.rethinkrobotics.com/wiki/Main_Page**

## License

[![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)](http://creativecommons.org/publicdomain/zero/1.0/)
