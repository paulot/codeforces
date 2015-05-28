#!/usr/bin/env python2.6

dp = {
    '2': '2',
    '3': '3',
    '4': '223',
    '5': '5',
    '6': '35',
    '7': '7',
    '8': '2227',
    '9': '7332'
}

raw_input()
num = [s for s in raw_input() if s != '1' and s != '0']
print ''.join(sorted(''.join([dp[n] for n in num]), reverse=True))
