#!/usr/bin/env python2.6
line = [int(i) for i in raw_input().split(' ')]
ne, nn = line[0], line[1]

num_teams = 0;

for A in range(min(ne, nn/2) + 1):
  nea = ne-A
  nna = nn-2*A
  neb = ne-nea
  nnb = nn-nna
  B = min(nn-nnb, (ne-neb)/2)
  num_teams = max(A+B, num_teams)

print num_teams
