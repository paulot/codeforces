n, k = map(int, raw_input().split(' '))
scores, passed, c = map(int, raw_input().split(' ')), 0, k

while c < n and scores[k-1] == scores[c]:
    c += 1
print len(filter(lambda a: a > 0, scores[0:c]))
