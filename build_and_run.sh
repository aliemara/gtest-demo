#!/bin/bash
set -e
# rm -rf build # clean, if needed
mkdir -p build
cd build
cmake ..
cmake --build .
./bin/unit_tests
cd ..
