#!/bin/bash

CURRENT_DIR=$(pwd)

SOURCE_DIR="$CURRENT_DIR/simulation_ws/src/sim/models"

GAZEBO_MODELS_DIR="$HOME/.gazebo/models"

cp -r "$SOURCE_DIR"/* "$GAZEBO_MODELS_DIR" || { echo "Error: Failed to copy models to $GAZEBO_MODELS_DIR"; exit 1; }

echo "Models have been successfully copied to $GAZEBO_MODELS_DIR"

PACKAGE_XML_PATH="$CURRENT_DIR/simulation_ws/src/sim/package.xml"

sed -i "s|<gazebo_ros gazebo_model_path = \".*\"/>|<gazebo_ros gazebo_model_path = \"$HOME/.gazebo/models\"/>|g" "$PACKAGE_XML_PATH"

echo "package.xml has been updated with the correct gazebo_model_path"

cd "$CURRENT_DIR/simulation_ws"

echo "Current directory is now $(pwd)/simulation_ws"
