#!/usr/bin/env bash

# Add ARM HF for BeagleBone
sudo dpkg --add-architecture armhf
sudo dpkg --print-foreign-architectures

# Get latest packages
sudo apt update

# Get development tools
sudo apt install crossbuild-essential-armhf -y

# Get CppCMS prerequisites
sudo apt install libpcre3-dev:armhf -y
sudo apt install zlib1g-dev:armhf -y
sudo apt install libgcrypt11-dev:armhf -y
sudo apt install libicu-dev:armhf -y

# Get test prerequisites
sudo apt install libcurl4-openssl-dev:armhf -y