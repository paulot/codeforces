from collections import Counter
from itertools import izip

def ncr(n, r):
    return reduce(lambda x, y: x * y[0] / y[1], izip(xrange(n - r + 1, n+1), xrange(1, r+1)), 1)

n, f = int(raw_input()), sorted(map(int, raw_input().split()))
c = Counter(f)
print f[len(f) - 1] - f[0], c[f[0]] * c[f[len(f) - 1]] if f[0] != f[len(f) - 1] else ncr(len(f), 2)
