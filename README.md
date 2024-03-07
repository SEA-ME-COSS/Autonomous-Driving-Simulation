# PiRacer Simulation with ROS2 and Gazebo

<div width="100%" align="center">
    <img width="49%" src="/images/design.png">
    <img width="49%" src="/images/model.png">
</div>

---

This repository provides tools and examples for controlling and experimenting with **PiRacer model vehicle** in Gazebo. The Gazebo model, designed to match the hardware specifications of PiRacer, can be controlled via ROS2 topic communication. The included teleoperation example is a simple demonstration using the WASD keys on the keyboard, allowing simultaneous control of both the real PiRacer and the PiRacer in Gazebo.

The idea is to utilize this repository as a template for **digital twin** research. By equipping PiRacer with sensors such as odometer, IMU, LiDAR, etc., and implementing closed-loop feedback control, it would be possible to more accurately replicate the behavior of the real-world PiRacer in Gazebo.

| ![Throttle](/images/throttle.gif) | ![Steering](/images/steering.gif) |
|:---:|:---:|
| Throttle | Steering |

## Contents

```shell
./
 ├── simulation_ws/src/
 │   └── sim        # Description and launch file for PiRacer model
 │
 └── teleoperation_ws/src/
     └── teleop     # Remote control example including a controller and a receiver
```

Put communication img here

## Requirements

ros2, gazebo, pygame, piracer

Laptop_Ubuntu20.04
RaspberryPi_Ubuntu20.04

## Usage


```bash
# comment
sudo ~~~
```

## References

- [Waveshare PiRacer](https://www.waveshare.com/wiki/PiRacer_AI_Kit)
