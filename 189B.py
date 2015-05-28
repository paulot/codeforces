#!/usr/bin/env python2.6
line = [int(i) for i in raw_input().split(' ')]
w, h = line[0], line[1]

ways = 0
for dh in xrange(1, h, 2):
  for dw in xrange(1, w, 2):
    ways += (w-dw) * (h-dh)
print ways
