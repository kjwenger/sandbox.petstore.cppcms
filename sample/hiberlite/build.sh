#!/usr/bin/env bash

clear
g++ main.cpp -I ../../usr/include  -L ../../usr/lib -l hiberlite -l pthread -l dl -o run && \
./run && \
sqlite3 sqlite3.db '.tables' && \
sqlite3 sqlite3.db 'select * from person' && \
sqlite3 sqlite3.db 'select * from person_bio_items'
