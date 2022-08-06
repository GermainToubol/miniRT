#!/bin/bash

FILES="./demo/*.rt"
for f in $FILES; do
	echo "Proceding $f...";
	./miniRT $f;
done
