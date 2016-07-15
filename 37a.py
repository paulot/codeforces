from collections import Counter
raw_input()
bars = Counter(map(int, raw_input().split()))
print max(bars.values()), len(bars.keys())
