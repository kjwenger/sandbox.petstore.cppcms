#!/usr/bin/env bash

#set -x

CURRENT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"

cd "${PROJECT_DIR}"
./build/sandbox-cppcms -c config.json &
sleep 1
./build/sandbox-cppcms-test
sudo pkill -9 sandbox-cppcms
cd "${CURRENT_DIR}"
