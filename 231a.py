n = int(raw_input())
print len(filter(lambda a: sum(map(int, raw_input().split())) >= 2, range(0, n)))
