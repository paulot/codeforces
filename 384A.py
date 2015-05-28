#!/usr/bin/env python2.6
def getChar(i, j):
  if i % 2 == 0:
    return 'C' if j % 2 == 0 else '.'
  else:
    return 'C' if j % 2 != 0 else '.'

n = int(raw_input())

s = []
for i in range(n):
  s.append(''.join([getChar(i, j) for j in range(n)]))
print sum([sen.count('C') for sen in s])
for i in range(n):
  print s[i]
