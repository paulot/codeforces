import re

def to_let(num):
    return 'abcdefghijklmnopqrstuvwxyz'[num - 1] if num <= 26 else to_let((num - 1)/26) + to_let(num%26)

def to_num(let):
    return ('abcdefghijklmnopqrstuvwxyz'.index(let[len(let) - 1]) + 1) + to_num(let[0:len(let) - 1]) * 26 if let else 0

n = int(raw_input())
ints = lambda i: map(int, re.findall(r'\d+', i))

for coord in [raw_input().lower() for _ in xrange(0, n)]:
    nums = ints(coord)
    if len(nums) == 2:
        print to_let(nums[1]).upper() + str(nums[0])
    else:
        print 'R' + str(nums[0]) + 'C' + str(to_num(''.join(filter(lambda a: not a.isdigit(), coord))))

