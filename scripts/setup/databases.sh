#!/usr/bin/env bash

CURRENT_DIR="$(pwd)"
SETUP_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(dirname "${SETUP_DIR}")"
PROJECT_DIR="$(dirname "${SCRIPTS_DIR}")"

# Create databases
pushd "${PROJECT_DIR}"
rm -f petstore_dev.db
touch petstore_dev.db
rm -f sqitch.db
touch sqitch.db
if [ ! -f sqitch.conf ]; then
    sqitch init "sandbox.cppcms" \
           --uri https://github.com/theory/sqitch-sqlite-intro/ \
           --engine sqlite
    sqitch config --user engine.sqlite.client /usr/local/bin/sqlite3
    sqitch config --user user.name "Klaus Wenger"
    sqitch config --user user.email "kjwenger@yahoo.com"
    sqitch add category -n "Creates table to track our category."
    sqitch add tag -n "Creates table to track our tag."
    sqitch add user -n "Creates table to track our user."
    sqitch add order -n "Creates table to track our order."
    sqitch add pet -n "Creates table to track our pet." \
                   --requires category \
                   --requires tag
    sqitch target add petstore_dev db:sqlite:petstore_dev.db
    sqitch engine add sqlite petstore_dev
fi
sqitch deploy
sqlite3 petstore_dev.db '.tables'
sqitch verify
sqitch status
popd
