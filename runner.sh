#!/bin/bash

cd bin

for i in `ls | grep -v "\."`; do
    ./$i
done
