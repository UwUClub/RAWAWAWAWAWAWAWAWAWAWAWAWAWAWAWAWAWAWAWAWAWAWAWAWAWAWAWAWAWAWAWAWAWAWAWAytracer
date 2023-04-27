#! /bin/bash

#check if there is a build directory
if [ -d "build" ]; then
    rm -rf build
fi
mkdir build
cd build
cmake ..
make -j16
cd ..
