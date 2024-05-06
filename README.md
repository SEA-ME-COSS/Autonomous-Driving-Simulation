# Simulation

| cmd_vel (throttle) | 1.0     | 2.0     | 3.0     | 4.0     | 5.0     |
|--------------------|---------|---------|---------|---------|---------|
| <max_speed> 1      | 0.3 m/s | 0.3 m/s | 0.3 m/s | 0.3 m/s | 0.3 m/s |
| <max_speed> 2      | 0.3 m/s | 0.6 m/s | 0.6 m/s | 0.6 m/s | 0.6 m/s |
| <max_speed> 3      | 0.3 m/s | 0.6 m/s | 0.9 m/s | 0.9 m/s | 0.9 m/s |
| <max_speed> 4      | 0.3 m/s | 0.6 m/s | 0.9 m/s | 1.2 m/s | 1.2 m/s |
| <max_speed> 5      | 0.3 m/s | 0.6 m/s | 0.9 m/s | 1.2 m/s | 1.5 m/s |

## Note

```bash
# Put models to .gazebo to solve rviz2 texture problem
cd simulation_ws/src/sim/models
cp -r * ~/.gazebo/models
```

## Usage

```bash
ros2 launch sim sim.launch.py
ros2 run teleop controller
```
