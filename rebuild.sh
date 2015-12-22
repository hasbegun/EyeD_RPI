#!/bin/bash 
set -e

rm CMakeCache.txt
rm Makefile
rm cmake_install.cmake
rm -rf CMakeFiles

cmake .
make
