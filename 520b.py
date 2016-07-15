n, m = map(int, raw_input().split())
q, v = [(n, 0)], set()

while len(q) > 0:
  n, path = q.pop(0)
  if n == 0 or n in v: continue
  v.add(n)
  if n == m:
    print path
    exit(0)

  if n > m:
    q += [(n-1, path+1)]
  else:
    q += [(n*2, path+1), (n-1, path+1)]
