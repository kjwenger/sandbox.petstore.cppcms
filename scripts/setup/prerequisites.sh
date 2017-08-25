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
sudo apt install autotools-dev -y
sudo apt install autoconf -y
sudo apt install libtool -y
sudo apt install libpam0g-devc

sudo apt install clang-3.9 -y
sudo apt install clang-3.9-doc -y
sudo apt install clang-3.9-examples -y
sudo apt install clang-format-3.9 -y
sudo apt install clang-tidy-3.9 -y

# Get CppCMS prerequisites
sudo apt install libpcre3-dev -y
sudo apt install zlib1g-dev -y
sudo apt install libgcrypt11-dev -y
sudo apt install libicu-dev -y
sudo apt install python -y

# Get test prerequisites
sudo apt install libcurl4-openssl-dev -y
sudo apt install libjsoncpp-dev -y
sudo apt install libjsoncpp1 -y

# Get database SQLite
sudo apt install sqlite3 -y
sudo apt install libsqlite3-dev -y

# Get database tools
sudo apt install libdbd-sqlite3-perl -y
sudo apt install sqitch -y
