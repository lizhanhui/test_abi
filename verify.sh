#!/bin/bash

if test -d bak; then
   rm -fr bak
fi
mkdir bak

if test -d build; then
   rm -fr build
fi
mkdir build

cd build
cmake ..
make
cp test_abi ../bak
rm -fr *
cmake -DTALK=ON ..
make
./test_abi
cp ../bak/test_abi test_abi_old
./test_abi_old
