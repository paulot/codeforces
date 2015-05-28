#include <iostream>
#include <string>
#define ll unsigned long long
#define num(c) (c-'0')

using namespace std;

ll zeroes[1000001] = {0};

int main() {
  int s;
  cin >> s;
  string str;
  cin >> str;

  // Count zeroes
  for (int i = str.size() - 1; i >= 0; i--) {
    if (num(str[i]) == 0)
      zeroes[i] += 1 + zeroes[i+1];
  }

  if (s == 0) {
    ll sum = 0;
    for (int i = 0; i < str.size(); i++) {
      sum += zeroes[i];
    }
    cout << sum << '\n';
    return 0;
  }

  /*
  for (int i = 0; i < str.size(); i++) {
    cout << zeroes[i] << ' ';
  }
  cout << endl;
  */

  ll back = 0, front = 0;
  ll sum = num(str[0]), ways = 0;
  while (back < str.size()) {
    // cout << back << ' ' << front << ' ' << sum << endl;
    if (sum == s) {
      if (zeroes[back] and zeroes[front]) {
        ways += zeroes[back] * zeroes[front];
        back += zeroes[back];
      } else if (zeroes[back]) {
        ways += zeroes[back] + 1;
        if (front == str.size() - 1) break;
        front++;
        sum += num(str[front]);
      } else {
        ways += 1;
        if (front == str.size() - 1) break;
        front++;
        sum += num(str[front]);
      }
    } else if (sum < s) {
        if (front == str.size() - 1) break;
        front++;
        sum += num(str[front]);
    } else {
        sum -= num(str[back]);
        back++;
    }
  }
  cout << ways << '\n';

  return 0;
}
