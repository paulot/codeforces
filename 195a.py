import math
size, band, dur = map(int, raw_input().split())

l, r = (size*dur)/band + 1, 0;
while l > r:
  mid = (l+r)/2
  if mid+dur >= math.ceil((size*dur)/float(band)):
    l = mid
  else:
    r = mid+1
print l
