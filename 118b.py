n = int(raw_input())

for i in xrange(0, n + 1):
    print ' '.join([' '] * (n - i) + map(str, range(0, i + 1)) + map(str, range(i-1, -1, -1)))

for i in xrange(n - 1, -1, -1):
    print ' '.join([' '] * (n - i) + map(str, range(0, i + 1)) + map(str, range(i-1, -1, -1)))
