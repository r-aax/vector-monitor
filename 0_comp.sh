#!/bin/sh

rm -f vector-monitor
g++ \
    -DSCALAR \
    ./src/*.cpp -o vector-monitor

./vector-monitor
