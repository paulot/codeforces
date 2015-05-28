#!/usr/bin/env python2.6
board = [raw_input() for _ in range(8)]
val = { 'q': 9,
        'r': 5,
        'b': 3,
        'n': 3,
        'p': 1 }
w, b = 0, 0
for i in range(8):
  for j in range(8):
    if board[i][j] != '.' and board[i][j].lower() != 'k':
      if board[i][j].isupper():
        w += val[board[i][j].lower()]
      else:
        b += val[board[i][j]]
print 'White' if w > b else 'Draw' if w == b else 'Black'
