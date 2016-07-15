n, m = map(int, raw_input().split())
n_pairs = lambda a: (a**2-a) // 2
maxnum = n_pairs(n-(m-1))
minnum = m * n_pairs(n//m) if n % m == 0 else (n%m)*n_pairs((n//m) + 1) + (m - (n%m)) * n_pairs(n//m)
print minnum, maxnum
