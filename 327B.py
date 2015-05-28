#!/usr/bin/env python2.6
import sys

def sieve(n):
  num = 1000000;
  for i in xrange(n):
    sys.stdout.write(str(num))
    if i < n-1:
      sys.stdout.write(' ')
    num += 1
  print

sieve(int(raw_input()))
