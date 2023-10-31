#!/bin/bash
seq 1 110 | awk 'BEGIN {srand()} {print rand() "\t" $0}' | sort -k1,1n | awk '{print $2}' | head -n 3000 | tr '\n' ' '