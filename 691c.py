num = list(raw_input())
start, end = 0, len(num)-1
while num[start] == '0':
    start += 1

try:
    dot = num.index('.')
    del num[dot]
    end -= 1
    while num[end] == '0':
        end -= 1

    if dot ==  start:
        p = -1
        while num[start] == '0':
            start += 1
            p -= 1
        print num[start] + '.' + ''.join(num[start+1:end+1]) + 'E' + str(p) if end-start > 0 else num[start] + 'E' + str(p)
    else:
        p = dot - 1 - start
        if p == 0:
            print num[start] + '.' + ''.join(num[start+1:end+1]) if end-start > 0 else num[start]
        else:
            print num[start] + '.' + ''.join(num[start+1:end+1]) + 'E' + str(p) if end-start > 0 else num[start] + 'E' + str(p)

except ValueError:
    p = end-start
    while num[end] == '0':
        end -= 1

    if p == 0:
        print num[start]
    else:
        print num[start] + '.' + ''.join(num[start+1:end+1]) + 'E' + str(p) if end-start > 0 else num[start] + 'E' + str(p)

