#!/usr/bin/env bash

#set -x

CPUS=$(lscpu | grep "^CPU(s):" | sed s/"CPU(s):                "//)

CURRENT_DIR="$(pwd)"
THIRDPARTY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(dirname "${THIRDPARTY_DIR}")"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"
USR_DIR="${PROJECT_DIR}/usr"

cd "${THIRDPARTY_DIR}"
git clone https://github.com/curl/curl.git curl --recursive
pushd curl
chmod +x ./buildconf
./buildconf
export CROSS=arm-linux-gnueabihf
export CC="${CROSS}-gcc"
export LD="${CROSS}-ld"
export AR="${CROSS}-ar"
export AS="${CROSS}-as"
export NM="${CROSS}-nm"
export RANLiB="${CROSS}-ranlib"
chmod +x ./configure
./configure \
    --target="${CROSS}" \
    --host="${CROSS}" \
    --prefix="${USR_DIR}/arm-linux-gnueabihf"
make -j ${CPUS}
make -j ${CPUS} install
popd
cd "${CURRENT_DIR}"
