#!/usr/bin/env python2.6
line = [int(i) for i in raw_input().split(' ')]
n = line[0]
line = sorted(line[1:])
a, b, c = line[0], line[1], line[2]
m = 0

for x in reversed(range(0, (n/a)+1)):
  if m <= n/min(b,c) and m != n/a:
    for y in reversed(range(0, ((n-a*x)/b)+1)):
      z = (n-a*x-b*y)/c
      if a*x+b*y+c*z==n:
        m = max(m, x+y+z)
print m
