#!/bin/bash

FILES="./demo/*.rt"
for f in $FILES; do
	echo "Proceding $f...";
    ./miniRT_bonus -v $f;
done
