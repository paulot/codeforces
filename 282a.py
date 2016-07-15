n, total = int(raw_input()), 0

for _ in xrange(0, n):
    total += 1 if '++' in raw_input() else -1
print total
