#!/usr/bin/env bash

CURRENT_DIR="$(pwd)"
SETUP_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(dirname "${SETUP_DIR}")"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"

# Create databases
touch "${PROJECT_DIR}/petstore_dev.db"
touch "${PROJECT_DIR}/petstore_test.db"
touch "${PROJECT_DIR}/petstore_prod.db"

