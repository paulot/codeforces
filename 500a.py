n, t = map(int, raw_input().split())
arr = map(int, raw_input().split()) + [0]
t -= 1

visited, cur = set(), 0
while cur not in visited:
  if cur == t:
    print 'YES'
    exit()
  visited.add(cur)
  cur = (cur + arr[cur]) % n

print 'NO'
