n, m, k = map(int, raw_input().split())

def check(num):
  global k
  ways = 0
  for i in xrange(1, n+1):
    ways += min(m, num/i)
  return ways

l, r = n*m+1, 0
while l > r:
  mid = (r+l)/2
  if check(mid) < k:
    r = mid+1
  else:
    l = mid
print l
