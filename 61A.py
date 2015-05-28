#!/usr/bin/env python2.6
num = raw_input()
a = int(num, 2)
b = int(raw_input(), 2)

ans = a ^ b
ans = bin(ans)[2:]
print '0' * (len(num)-len(str(ans))) + str(ans)
