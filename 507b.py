r, x, y, xi, yi = map(int, raw_input().split())
dist = ((xi - x)**2 + (yi - y)**2)**.5
print int(dist)//(r*2) + (1 if not dist.is_integer() or dist % (r*2) != 0 else 0)
