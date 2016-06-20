# TER M1 ISTR Université Paul Sabatier Toulouse France 2016

> Command of the simulation

## Authors
- __Bruno DATO__ -- bruno.dato.meneses@gmail.com
- __Abdellah ELGOURAIN__ -- elgourain@gmail.com
- __Evgeny SHULGA__ -- hlebovod@mail.ru

## TO DO

1. **In ~/ ... /Ligne_transitique_MONTRAC/ros_ws/src/commande/src :**

	- replace the file *main_commande.cpp* by *main_commande 12 aiguillages 6 navettes.cpp*
	- rename *main_commande 12 aiguillages 6 navettes.cpp* by *main_commande.cpp*


2. **In a terminal, launch roscore if you haven't done it yet**


3. **In a new terminal, in ~/ ... /Ligne_transitique_MONTRAC/ros_ws**

	- $ source devel/setup.bash
	- $ catkin_make


4. **In ~/ ... /Ligne_transitique_MONTRAC**

	- $ ./simulation 1 2 3 4 5 6 	(we use all the shuttles for this command)
	- if the simulation doesn't lauch successfully try a second time before restarting all the steps


4. **In a new terminal, in ~/ ... /Ligne_transitique_MONTRAC/ros_ws**

	- $ source devel/setup.bash
	- $ rosrun commande run
	- once the simulation is detected :  SIMULATION ON and LIGNE TRANSITIQUE OFF
	- press play on the simulation 

	- if the shuttles don't stop on at the 2 initilization points, change the positions *12* and *24* respectively by *24* ant *12* in the fonction *Deplacer_navettes_2(STx,RxD,RxG,Vx,Dx,PIx,Actionneurs,12,24)* line 102, save and restart all the steps.




## License

[![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)](http://creativecommons.org/publicdomain/zero/1.0/)
