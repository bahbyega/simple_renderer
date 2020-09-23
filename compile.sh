#!/bin/bash
cd src
make
cd ../build
./main
mkdir -p output
cd ../output
eog output.tga
cd ..
echo "Done."
