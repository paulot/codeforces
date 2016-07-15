def e(p):
    return 1 if p <= 1 else 10 ** (p - 1) + e(p-1)

def dig(num):
    n = (9 * e(len(str(num)))) // 10
    return len(str(num)) * (num - n) + dig(n) if n != 0 else num

print dig(int(raw_input()))
