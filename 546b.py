n, nums = int(raw_input()), sorted(map(int, raw_input().split()))
seen, numset, tsum = set(), set(nums), 0
for num in nums:
    if num in seen:
        a = num
        while a in numset:
            a += 1
            tsum += 1
        seen.add(a)
        numset.add(a)
    else:
        seen.add(num)
print tsum
