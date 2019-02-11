#!/bin/sh

# install bionic vulkan sdk
wget -qO - http://packages.lunarg.com/lunarg-signing-key-pub.asc | sudo apt-key add -
sudo wget -qO /etc/apt/sources.list.d/lunarg-vulkan-1.1.97-bionic.list http://packages.lunarg.com/vulkan/1.1.97/lunarg-vulkan-1.1.97-bionic.list
sudo apt update
sudo apt install lunarg-vulkan-sdk

sudo apt install libglfw3-dev
