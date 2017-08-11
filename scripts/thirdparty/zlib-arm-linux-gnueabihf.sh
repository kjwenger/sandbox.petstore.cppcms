#!/usr/bin/env bash

#set -x

CPUS=$(lscpu | grep "^CPU(s):" | sed s/"CPU(s):                "//)

CURRENT_DIR="$(pwd)"
THIRDPARTY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(dirname "${THIRDPARTY_DIR}")"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"
USR_DIR="${PROJECT_DIR}/usr"
ZLIB_DIR="${THIRDPARTY_DIR}/zlib"
TMP_DIR="${PROJECT_DIR}/tmp"

mkdir -p "${ZLIB_DIR}"
mkdir -p "${TMP_DIR}"
cd "${TMP_DIR}"
wget -c https://netix.dl.sourceforge.net/project/gnuwin32/zlib/1.2.3/zlib-1.2.3-src.zip
unzip -o -d zlib-1.2.3-src zlib-1.2.3-src.zip
cd "${TMP_DIR}/zlib-1.2.3-src/src/zlib/1.2.3/zlib-1.2.3/"
cp -R * "${ZLIB_DIR}"
cd "${CURRENT_DIR}"

cd "${ZLIB_DIR}"
make -j ${CPUS} distclean
export CROSS=arm-linux-gnueabihf
export CC="${CROSS}-gcc"
export LD="${CROSS}-ld"
export AS="${CROSS}-as"
chmod +x ./configure
./configure --prefix="${USR_DIR}/arm-linux-gnueabihf"
make -j ${CPUS}
make -j ${CPUS} install
cd "${CURRENT_DIR}"
