n = int(raw_input())
negs, pos = 0, 0
for _ in xrange(0, n):
  s, num = map(int, raw_input().split())
  if s < 0:
    negs += num
  else:
    pos += num

print min(negs, pos) * 2 + (1 if negs != pos else 0)
