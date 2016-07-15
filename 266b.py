def next_state(state):
    new_state = list(state)
    for i in xrange(1, len(state)):
        if state[i-1] == 'B' and state[i] == 'G':
            new_state[i-1], new_state[i] = new_state[i], new_state[i-1]
    return ''.join(new_state)

a, b = map(int, raw_input().split())
q = raw_input()

for _ in xrange(0, b):
    q = next_state(q)
print q
