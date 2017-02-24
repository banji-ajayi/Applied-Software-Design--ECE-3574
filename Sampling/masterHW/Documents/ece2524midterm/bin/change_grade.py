#!/usr/bin/env python
# ECE 2524 Homework 3 Problem 1
# Thomas Elliott

import argparse
import sys
import fileinput

parser = argparse.ArgumentParser(description='Change some grades')
parser.add_argument("argName")
parser.add_argument("argGrade")
parser.add_argument("infile", nargs='*')
args = parser.parse_args()


for data in fileinput.input(args.infile):
    (name, comma,  grade) = data.rpartition(',')
    findName = name.find(args.argName);
    if findName == -1:
        print data
    else:
        print name
        print ','
        print grade    
