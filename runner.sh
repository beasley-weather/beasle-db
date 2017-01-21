#!/bin/bash

cd bin

for i in `ls | grep -v "\."`; do
    ./$i $1
    echo
done
