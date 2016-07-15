get = lambda: map(int,input().split())
a, b, n = get()

def getSum(n):
  global a, b, l
  return (n-l+1)*a+((l+n)*((n-l+1)/2)-(n-l+1))*b

for _ in range(0, n):
  l, t, m = get()
  if a+(l-1)*b > t:
    print(-1)
    continue
  high, low = m*t, l
  while high-low > 1:
    mid = (high+low)//2
    s = getSum(mid)
    if a+(mid-1)*b <= t:
      if getSum(mid) > m*t:
        high = mid
      else:
        low = mid
    else:
      high = mid
  print(low)
