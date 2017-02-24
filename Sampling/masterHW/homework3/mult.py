#!/usr/bin/env python
# ECE 2524 Homework 3 Problem 1
# Thomas Elliott

import argparse
import sys

parser = argparse.ArgumentParser(description='Multiply some integers.')
args = parser.parse_args()

product = 1

for data in iter(sys.stdin.readline,  ''):
    try:
        if data == '\n':
            print product
            product = 1
        else:
            product *= int(data)
    
    except ValueError as e:
        e = "You must use only integers, other characters are not excepted\n"
        sys.stderr.write(e)
        sys.exit(1)
print product
