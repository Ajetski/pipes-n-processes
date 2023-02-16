#!/bin/bash

mkdir -p out

echo "building subsystems..."
for SRC_FILE in $(ls -l src | grep \.cpp | sed 's/.* //' | sed 's/\.cpp//')
do
    echo "compiling $SRC_FILE.cpp"
    g++ -pthread -o out/$SRC_FILE src/$SRC_FILE.cpp
done

cd out
echo ""
echo "running driver:"
./cpu
