#!/usr/bin/env python

import re
import fileinput
from sys import stderr,stdout,argv,exit

verbose=False

if len(argv) != 2:
    stderr.write("Usage: myprog.py STRING\n")
    exit(1)
    
for line in fileinput.input('-'):
    m = re.search(argv[1], line)
    values = line.rstrip().split(None) #note that split accepts an optional parameter to define what character the string is split on. If none is provided it defaults to any whitespace character
    if m:
        if verbose:
            stderr.write("%r\n" % values)
        values[4] = re.sub(r'([\d]{3})[- ]?([\d]{3})[- ]?([\d]{4})',r'+1 (\1) \2-\3',values[4])

        print ";".join(values)
