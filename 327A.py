#!/usr/bin/env python2.6
raw_input()
line = [int(n) for n in raw_input().split(' ')]

cmax, tmax = 0, 0
start = 0
for i in range(len(line)):
  cmax += 1 if not line[i] else -1
  tmax = max(cmax, tmax)
  if cmax < 0:
    cmax = 0

if sum(line) == len(line):
  print sum(line)-1
else:
  print sum(line) + tmax

