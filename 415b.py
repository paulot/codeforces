f=lambda: map(int, raw_input().split())
n,a,b=f()
print ' '.join([str(x*a%b/a) for x in f()])
