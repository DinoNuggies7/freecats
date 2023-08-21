#!/bin/bash

for j in {0..43}
do
	./convert.sh $j ../src/ > temp
done