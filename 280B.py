line = raw_input().split()
n, l = int(line[0]), int(line[1])*10e10
lan = [int(x)*10e10 for x in raw_input().split()]

lan.sort()

# print lan

def check(d):
  if lan[0]-d > 0 or lan[n-1]+d < l:
    return False

  if n == 2 and (lan[n-1]-d > lan[0]+d):
    return False

  for i in xrange(1, n-1):
    if lan[i]-d > lan[i-1]+d or lan[i+1]-d > lan[i]+d:
      return False

  return True


low, high = 0, l
while high-low > 1:
  mid = (high+low)/2
  print high, low

  if check(mid):
    high = mid;
  else:
    low = mid + 1;

print high/10e10

