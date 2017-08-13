#!/usr/bin/env bash

#set -x

CPUS=$(lscpu | grep "^CPU(s):" | sed s/"CPU(s):                "//)

CURRENT_DIR="$(pwd)"
PARENT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
THIRDPARTY_DIR="${PARENT_DIR}"
SCRIPTS_DIR="$(dirname "${THIRDPARTY_DIR}")"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"
USR_DIR="${PROJECT_DIR}/usr"

cd "${THIRDPARTY_DIR}"
git clone https://github.com/paulftw/hiberlite.git hiberlite --recursive
pushd hiberlite
sed -i 's/INSTALL_PREFIX = \/usr/INSTALL_PREFIX ?= \/usr/g' Makefile
sed -i 's/gcc/$(CC)/g' Makefile
sed -i 's/g++/$(CXX)/g' Makefile
sed -i.old '1s/^/CC ?= gcc\nCXX ?= g++/' Makefile
INSTALL_PREFIX="${USR_DIR}/arm-linux-gnueabihf"
CC=/usr/bin/arm-linux-gnueabihf-gcc
CXX=/usr/bin/arm-linux-gnueabihf-g++
make -j ${CPUS} clean   INSTALL_PREFIX="${INSTALL_PREFIX}" CC="${CC}" CXX="${CXX}"
make -j ${CPUS}         INSTALL_PREFIX="${INSTALL_PREFIX}" CC="${CC}" CXX="${CXX}"
make -j ${CPUS} install INSTALL_PREFIX="${INSTALL_PREFIX}" CC="${CC}" CXX="${CXX}"
popd
popd
cd "${CURRENT_DIR}"
