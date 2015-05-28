#!/usr/bin/env python2.6
line = raw_input().split(' ')
n = int(line[0])
m = int(line[1])

print (n/2)*m + (n%2)*(m/2)
