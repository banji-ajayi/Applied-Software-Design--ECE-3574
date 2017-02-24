#!/usr/bin/env python
# ECE 2524 Homework 3 Problem 2
# Thomas Elliott

import argparse
import sys
import fileinput

parser = argparse.ArgumentParser(description='Multiply some integers.')
parser.add_argument("--ignore-blanks",  help="skips over blank lines if they are entered",  action = "store_true")
parser.add_argument("--ignore-non-numeric",  help="skips over charactres that aren't integers", action = "store_true")
parser.add_argument("infile", nargs='*')

args = parser.parse_args()

#had to write my own function to check if entry is an integer, because isdigit() did not like single characters, like '2' for some reason
def isInt(data):
    try:
        int(data)
        return True        
    except ValueError:
        return False

product = 1

for data in fileinput.input(args.infile):
    if args.ignore_non_numeric:
        if isInt(data):
            product *= int(data)
        else:
            continue
    
    #use try block to catch non integer exceptions if ignore-non-numeric is not selected
    else:
        try:
            if data == '\n': #for displaying the product if a blank line is entered
                if args.ignore_blanks: #do not display product if blank line is enterd but --ignore-blanks option is used
                    continue
                else:
                    print product
                    product = 1
            else:
                product *= int(data)
        
        except ValueError as e:
            e = "You must use only integers, other characters are not excepted\n"
            sys.stderr.write(e)
            sys.exit(1)
print product
