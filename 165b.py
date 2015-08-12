n, k = [int(x) for x in raw_input().split()]

def check(v):
  global n
  global k
  num, den = v, k;
  while v/den > 0:
    num += v/den
    den *= k
  return num >= n

l, r = 0, 100000000000
while l < r:
  mid = (r+l)/2
  if check(mid):
    r = mid
  else:
    l = mid+1
print l


