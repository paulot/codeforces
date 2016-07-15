import math

def is_prime(num):
    if num % 2 == 0 and num > 2:
        return False
    for i in xrange(3, int(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return False
    return True

n, nums = raw_input(), map(int, raw_input().split())
print '\n'.join(map(lambda num: 'NO' if num == 1 or int(math.sqrt(num))**2 != num or not is_prime(int(math.sqrt(num))) else 'YES', nums))
