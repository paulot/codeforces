#!/usr/bin/env python2.6

def get(arr, i):
  try:
    return arr[i] if i >= 0 else 0
  except IndexError:
    return 0


string = raw_input()
n = int(raw_input())
qs = []
for i in range(n):
  qs.append([int(i) for i in raw_input().split(' ')])

dp = [0] * (len(string)-1)
num = 0
for i in range(len(string)-1):
  dp[i] = int(string[i] == string[i+1])
dp += [0]

s, dpi = 0, [0] * (len(string))
for i in range(len(string)):
  s += dp[i]
  dpi[i] = s

s, dpe = 0, [0] * (len(string))
for i in reversed(range(len(string))):
  s += dp[i]
  dpe[i] = s

for q in qs:
    print dpe[0]  - get(dpi, q[0]-2) - get(dpe, q[1]-1)
    #print sum(dp[q[0]-1:q[1]-1])
