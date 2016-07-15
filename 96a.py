a = raw_input()
b = a
a, b = a.split('1'), b.split('0')

print 'YES' if any(filter(lambda a: len(a) >= 7, a)) or any(filter(lambda a: len(a) >= 7, b)) else 'NO'
