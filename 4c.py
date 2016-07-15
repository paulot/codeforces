from collections import Counter

n, c = int(raw_input()), Counter()

for _ in xrange(0, n):
    w = raw_input()
    if w in c:
        print w + str(c[w])
    else:
        print 'OK'
    c[w] += 1
