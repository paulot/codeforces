word = raw_input()
if word.find('BA', (word.find('AB') + 2 if 'AB' in word else -1)) != -1 or word.find('AB', (word.find('BA') + 2 if 'BA' in word else -1)) != -1:
  print 'YES'
else:
  print 'NO'
