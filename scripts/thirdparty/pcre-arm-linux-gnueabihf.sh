#!/usr/bin/env bash

#set -x

CPUS=$(lscpu | grep "^CPU(s):" | sed s/"CPU(s):                "//)

CURRENT_DIR="$(pwd)"
THIRDPARTY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(dirname "${THIRDPARTY_DIR}")"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"
USR_DIR="${PROJECT_DIR}/usr"

cd "${THIRDPARTY_DIR}"
svn co svn://vcs.exim.org/pcre/code/trunk pcre
cd pcre
mkdir -p build-arm-linux-gnueabihf
cd build-arm-linux-gnueabihf
rm -Rf *
cmake -DCMAKE_TOOLCHAIN_FILE="${PROJECT_DIR}/toolchains/arm-linux-gnueabihf.cmake" \
      -DCMAKE_INSTALL_PREFIX="${USR_DIR}/arm-linux-gnueabihf" \
      ..
make -j ${CPUS}
make -j ${CPUS} install
cd ..
cd ..
cd "${CURRENT_DIR}"
