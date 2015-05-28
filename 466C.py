#!/usr/bin/env python2.6
raw_input()
nums = [int(n) for n in raw_input().split(' ')]
s = sum(nums)
if s%3 != 0:
  print 0
  exit(0)

subsum = s/3
ways = 0

stoi = [0] * len(nums)
s = 0
for i in range(0, len(nums)):
  s += nums[i]
  stoi[i] = int(s == subsum)

for i in range(1, len(nums)):
  stoi[i] += stoi[i-1]

ss, ans = 0, 0
for i in reversed(range(2, len(nums))):
  ss += nums[i]
  if ss == subsum:
    ans += stoi[i-2]
print ans
