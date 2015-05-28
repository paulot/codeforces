#!/usr/bin/env python2.6
def get_smallest(sumd, big):
  for i, n in enumerate(sdigits[sumd]):
    if n > big:
      sdigits[sumd].pop(i)
      return n

n = int(raw_input())
nums = []
for i in xrange(n):
  nums.append(int(raw_input()))

before = -1
for n in nums:
  s = get_smallest(n, before)
  before = s
  print s




