#!/usr/bin/env python2.6
line = raw_input().split(' ')
n = int(line[0])
m = int(line[1])
a = int(line[2])

def solve(n, m, a):
  return (n/a + (not not (n%a))) * (m/a + (not not (m%a)))

print solve(n, m, a)
