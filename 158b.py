from collections import Counter

n, taxis = int(raw_input()), 0
nums = map(int, raw_input().split(' '))
count = Counter(nums)

for size in count:
    while count[size] > 0:
        if size == 4:
            count[size] -= 1
            taxis += 1
        if size == 3:
            count[size] -= 1
            taxis += 1
        if size == 2:
            count[size] -= 1
            taxis += 1
            if count[2] > 0:
                count[size] -= 1
        if size == 1:
            count[size] -= 1
            taxis += 1
            if count[3] > 0:
                count[3] -= 1
            elif count[2] > 0:
                count[2] -= 1
                if count[1] > 0:
                    count[1] -= 1
            elif count[1] > 0:
                count[1] -= min(3, count[1])
print taxis




