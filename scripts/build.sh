#!/usr/bin/env bash

CURRENT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

${CURRENT_DIR}/thirdparty/cppcms.sh

${CURRENT_DIR}/app.sh
