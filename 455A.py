#!/usr/bin/env python3
from itertools import groupby

input()
line = sorted([int(n) for n in input().split(' ')])
sums = {k:sum(list(g)) for (k, g) in groupby(line)}

dp = [0] * (len(sums) + 2)
for (i, num) in enumerate(sorted(sums.keys())):
  prev = dp[i] if sums.get(num-1) is not None else dp[i+1]
  dp[i+2] = max(dp[i+1], prev+sums[num])

print(dp[len(sums)+1])
