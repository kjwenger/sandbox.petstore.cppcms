#!/usr/bin/env bash

CURRENT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"

cd "${PROJECT_DIR}"
./build/sandbox-cppcms -c config.json
cd "${CURRENT_DIR}"
