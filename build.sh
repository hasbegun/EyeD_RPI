#!/usr/bin/env bash

rm -rf build
mkdir build
cd build

cmake -DCMAKE_PREFIX_PATH=/usr/local/opencv/2.4.9/osx ..
make -j8

cp EyeD_RPI ../bin
echo "Build done."
echo "Eyed_RPI is available at ./bin"
