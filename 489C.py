#!/usr/bin/env python2.6
def getNum(num, s, reverse):
  ran = range(len(num)) if reverse else reversed(range(len(num)))
  for i in ran:
    for n in range(num[i], 10):
      num[i] = n
      if sum(num) == s:
        return ''.join(str(x) for x in num)
  return -1

line = raw_input().split(' ')
l = int(line[0])
s = int(line[1])

minn = [1] + [0] * (l-1)
maxn = [1] + [0] * (l-1)
if l == 1 and s == 0:
  print 0, 0
else:
  print getNum(minn, s, False), getNum(maxn, s, True)
