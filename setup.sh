#!/bin/bash

# Set the path to the source models directory
SOURCE_DIR="$(pwd)/simulation_ws/src/sim/models"

# Set the path to the Gazebo models directory
GAZEBO_MODELS_DIR="$HOME/.gazebo/models"

# Copy all models from the source directory to the Gazebo models directory
cp -r "$SOURCE_DIR"/* "$GAZEBO_MODELS_DIR"

# Print a message indicating the completion of the task
echo "Models have been successfully copied to $GAZEBO_MODELS_DIR"
