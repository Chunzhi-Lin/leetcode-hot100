#!/bin/bash

build_dir="build"
include_dir="include"

mkdir -p build
gcc -O2 src/$1.c -I$include_dir -o $build_dir/test