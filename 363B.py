#!/usr/bin/env python2.6
line = [int(n) for n in raw_input().split(' ')]
n, k = line[0], line[1]
nums = [int(m) for m in raw_input().split(' ')]

mi, m = 0, float('inf')
s = 0
for i in xrange(k):
  s += nums[i]

for i in xrange(n-k+1):
  if i <= n-k:
    s -= nums[i]
  nums[i] += s
  if i+k < n:
    s += nums[i+k]

  if m > nums[i]:
    m = nums[i]
    mi = i
print mi + 1
