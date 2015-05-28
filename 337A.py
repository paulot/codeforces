#!/usr/bin/env python2.6
line = raw_input().split(' ')
n = int(line[0])
m = int(line[1])
puzzles = [int(num) for num in raw_input().split(' ')]
puzzles = sorted(puzzles)

ans = puzzles[n-1] - puzzles[0]
for i in range(1, m-n+1):
  ans = min(puzzles[i+n-1]-puzzles[i], ans)

print ans
