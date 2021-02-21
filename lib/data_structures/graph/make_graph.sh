#!/bin/bash

rm -rf build/
mkdir build && cd build/
cmake ../
make

rm ../dijkstra
cp dijkstra ../
