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
git clone https://github.com/google/googletest.git googletest
pushd googletest
mkdir -p build-arm-linux-gnueabihf
pushd build-arm-linux-gnueabihf
rm -Rf *
cmake -DCMAKE_TOOLCHAIN_FILE="${PROJECT_DIR}/toolchains/arm-linux-gnueabihf.cmake" \
      -DDISABLE_ICU_LOCALIZATION=ON \
      -DCMAKE_INSTALL_PREFIX="${USR_DIR}/arm-linux-gnueabihf" \
      ..
make -j ${CPUS}
make -j ${CPUS} install
popd
popd
cd "${CURRENT_DIR}"
