#!/bin/bash
cd src
make
cd ../build
./main
cd ../output
eog output.tga
cd ..
echo "Done."
