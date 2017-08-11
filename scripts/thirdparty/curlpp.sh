#!/usr/bin/env bash

#set -x

CPUS=$(lscpu | grep "^CPU(s):" | sed s/"CPU(s):                "//)

CURRENT_DIR="$(pwd)"
THIRDPARTY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(dirname "${THIRDPARTY_DIR}")"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"
USR_DIR="${PROJECT_DIR}/usr"

cd "${THIRDPARTY_DIR}"
git clone https://github.com/jpbarrette/curlpp.git curlpp
pushd curlpp
mkdir -p build
pushd build
rm -Rf *
cmake -DCMAKE_INSTALL_PREFIX="${USR_DIR}" \
      ..
make -j ${CPUS}
make -j ${CPUS} install
popd
popd
cd "${CURRENT_DIR}"
