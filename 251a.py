from bisect import bisect

n, d = map(int, raw_input().split())
arr = map(int, raw_input().split())

ways = 0;
for i in xrange(0, n):
  pos = bisect(arr, arr[i]+d, i)
  ways += (pos-i-1)*(pos-i-2)/2

print ways
