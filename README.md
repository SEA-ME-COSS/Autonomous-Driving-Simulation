# Simulation

## Usage

```bash
rviz2 -d rviz.rviz
ros2 launch sim sim.launch.py
ros2 run teleop controller
```

## Note

```bash
# Put models to .gazebo to solve rviz2 texture problem
cd simulation_ws/src/sim/models
cp -r * ~/.gazebo/models
```

change package xml