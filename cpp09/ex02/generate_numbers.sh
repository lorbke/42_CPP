#!/bin/bash
seq 1 11000 | awk 'BEGIN {srand()} {print rand() "\t" $0}' | sort -k1,1n | awk '{print $2}' | tr '\n' ' '