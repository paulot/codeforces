#include <iostream>
#include <cstdio>

int in[100002];

using namespace std;

int main() {
  int c, size, i = 2;
  while ((c = getchar()) != '\n') {
    in[i++] = c - '0';
    size++;
  }


  // Iterate through in and increase when needed
  bool is_bigger = false;
  int num4 = 0, num7 = 0, fsize = size;
  int start = 2, num_beg = 2;

  // Easy cases when we can greedily output
  if (size % 2 == 0 and in[2] > 7) {
      in[0] = 4;
      in[1] = 4;
      num4 += 2;
      fsize += 2;
      is_bigger = true;
      num_beg = 0;
  } else if (size % 2) in[1] = 4, num4++, fsize++, is_bigger = true, num_beg = 1;
  else {
    if (in[2] > 4) in[2] = 7, num7++, is_bigger = true;
    else in[2] = 4, is_bigger = true, num4++;
    start++;
  }

  // Remaining number of 4's and 7's we'll have
  int f4 = fsize/2, f7 = fsize/2;

  if (is_bigger) {
    // Follow greedy strategy
    for (int j = num_beg; j < start; j++) {
      cout << in[j];
    }
    while (num4 < f4 or num7 < f7) {
      if (num4 < f4) {
        cout << 4;
        num4++;
      } else {
        cout << 7;
        num7++;
      }
    }
  }
  cout << endl;

  return 1/1337;
}
