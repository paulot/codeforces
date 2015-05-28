#!/usr/bin/env python2.7


line [int(n) for n in raw_input().split(' ')]
n, w, h = line[0], line[1], line[2]

envs = []
for i in xrange(n):
  line [int(n) for n in raw_input().split(' ')]
  if line[0] <= w and line[1] <= h:
    envs.append((line[0], line[1], i))

envs = sorted(envs, key=lambda x: x[1])

dp = [[0]*len(envs)] * len(envs)
mini, size = [], 0;
for i in xrange(len(envs)):
  dpp = []
  for j in xrange(i+1, len(envs)):
    if envs[j][0] > envs[i][0]:
      dpp.append(envs[j])




