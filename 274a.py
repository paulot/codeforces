n, k = [int(x) for x in raw_input().split()]
nums = sorted([int(x) for x in raw_input().split()])
uniq = set(nums)
for x in nums:
  if k > 1 and x in uniq:
    uniq.discard(x*k)
print len(uniq)
