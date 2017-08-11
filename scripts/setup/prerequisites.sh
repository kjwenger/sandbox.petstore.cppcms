#!/usr/bin/env bash

# Get latest packages
sudo apt update

# Get network tools
sudo apt install curl -y
sudo apt install wget -y

# Get version control tools
sudo apt install git -y
sudo apt install subversion -y

# Get development tools
sudo apt install build-essential -y
sudo apt install gcc -y
sudo apt install g++ -y
sudo apt install cmake -y
sudo apt install cppcheck -y

# Get CppCMS prerequisites
sudo apt install libpcre3-dev -y
sudo apt install zlib1g-dev -y
sudo apt install libgcrypt11-dev -y
sudo apt install libicu-dev -y
sudo apt install python -y
