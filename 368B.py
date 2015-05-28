#!/usr/bin/env python2.6
nums = [int(n) for n in raw_input().split(' ')]
n, m = nums[0], nums[1]
nums = [int(n) for n in raw_input().split(' ')]
qs = []
for _ in range(m):
  qs.append(int(raw_input()))

dp = [0] * n
s = set()
for i in range(m):
  if i == n:
    break
  s.add(nums[i])
for i in range(n):


