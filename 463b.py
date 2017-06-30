n, pylons = int(raw_input()), map(int, raw_input().split())
s, e = pylons[0], 0
for i in xrange(1, n):
    if e + (pylons[i-1] - pylons[i]) < 0:
        s += -(e + (pylons[i-1] - pylons[i]))
        e = 0
    else:
        e += pylons[i-1] - pylons[i]
print s
