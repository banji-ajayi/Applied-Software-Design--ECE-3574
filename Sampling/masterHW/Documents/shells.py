# ECE 2524 Homework 2 Problem 1
# Thomas Elliott
with open('/etc/passwd', 'r') as f:
    for line in f:
        i = line.index(':')
        print line[0:i], '\t',

        lastColon = line.rfind(':')
        print line[lastColon+1:len(line)]
       
