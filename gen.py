#!/usr/bin/env python2.6
from random import randint as r
import sys

n, m = 46, 615683844
print n, m
for _ in xrange(0, n):
  sys.stdout.write(str(r(2000000, 600000000)) + ' ')
print
