num = raw_input()
s = 1 if num[0] == '4' else 2
for i in xrange(1, len(num)):
    s *= 2
    s += 1 if num[i] == '4' else 2
print s
