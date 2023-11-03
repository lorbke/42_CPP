#!/bin/bash
seq 1 30 | awk 'BEGIN {srand()} {print rand() "\t" $0}' | sort -k1,1n | awk '{print $2}' | tr '\n' ' '