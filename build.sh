#! /bin/bash

#check if there is a build directory
if [ -d "build" ]; then
    rm -rf build
fi
mkdir build
cd build
cmake ..
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
make -j16
cd ..
