# Gazebo Simulator

<img src=/images/Architecture_Simulation.png alt="Architecture_Simulation" width="100%" height="100%"/>

This repository is a Gazebo Simulator for the Autonomous Driving System. It was created to test the [ADS project](https://github.com/SEA-ME-COSS/Autonomous-Driving-System.git).

# Requirements

- Ubuntu 20.04
- [ROS2 foxy Installation](https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html)
- [Gazebo Simulation Installation](https://gazebosim.org/docs/garden/install_ubuntu)
    
    ```bash
    # Follow it if "Installation" is not working
    sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'
    wget https://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -
    sudo apt update
    
    sudo apt install gazebo11 libgazebo11-dev -y
    sudo apt install ros-foxy-gazebo-ros-pkgs -y
    
    sudo ubuntu-drivers autoinstall
    
    sudo reboot
    
    # After reboot
    gazebo
    ```
    

After this, close Gazebo and proceed with downloading the Simulation repository and setting up the environment.

```bash
https://github.com/SEA-ME-COSS/Autonomous-Driving-Simulation.git
cd Autonomous-Driving-Simulation
bash setup.sh
```

Once the setup is complete, build the project.

```bash
# Check you are in simulation_ws
colcon build --symlink-install
source install/setup.bash
```

Run the simulator!

```bash
ros2 launch sim sim.launch.py 
```

# Usage

Here are the basic steps to run the simulator.

If you want to visualize ROS2 topics using Rviz2, start Rviz2 before launching the simulation with the following commands:

```bash
source install/setup.bash
rviz2 -d rviz.rviz
ros2 launch sim sim.launch.py 
```

To control the vehicle using the keyboard, use the following command. The control keys are awsd.

```bash
source install/setup.bash
ros2 run teleop controller
```

For autonomous driving, refer to this [repository](https://github.com/SEA-ME-COSS/Autonomous-Driving-System.git).

# Reference

- [ROS2 foxy](https://docs.ros.org/en/foxy/index.html)
- [Gazebo](https://gazebosim.org/docs/garden/install_ubuntu)