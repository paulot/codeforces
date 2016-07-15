n, nums, i = int(raw_input()), map(int, raw_input().split()), 1
s, e = 0, 0

while i < n:
    if nums[i-1] <= nums[i]:
        i += 1
        continue
    else:
        break

s = i
while i < n:
    if nums[i-1] > nums[i]:
        i += 1
        continue
    else:
        break
e = i

while i < n:
    if nums[i-1] <= nums[i]:
        i += 1
        continue
    else:
        i = -1
        break

if i == n and (s - 1 <= 0 or nums[s-2] <= nums[e-1]) and (e == n or nums[e] >= nums[s-1]):
    print 'yes'
    print s, e
else:
    print 'no'
