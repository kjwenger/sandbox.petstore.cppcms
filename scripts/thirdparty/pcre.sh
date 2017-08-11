#!/usr/bin/env bash

#set -x

CPUS=$(lscpu | grep "^CPU(s):" | sed s/"CPU(s):                "//)

CURRENT_DIR="$(pwd)"
THIRDPARTY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(dirname "${THIRDPARTY_DIR}")"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"
USR_DIR="${PROJECT_DIR}/usr"

cd "${THIRDPARTY_DIR}"
sudo rm -Rf pcre
svn co svn://vcs.exim.org/pcre/code/trunk pcre
cd pcre
mkdir -p build
cd build
cmake -DCMAKE_INSTALL_PREFIX="${USR_DIR}" \
      ..
make -j ${CPUS}
make -j ${CPUS} install
cd ..
cd "${CURRENT_DIR}"
