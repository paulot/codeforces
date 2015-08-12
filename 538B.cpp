#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int qbins[] = { 
  1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,
  10000,10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,
  11011,11100,11101,11110,11111,100000,100001,100010,100011,100100,
  100101,100110,100111,101000,101001,101010,101011,101100,101101,
  101110,101111,110000,110001,110010,110011,110100,110101,110110,
  110111,111000,111001,111010,111011,111100,111101,111110,111111,
  1000000,1000001};

int get_max(int n) {
  auto i = upper_bound(begin(qbins), end(qbins), n);
  return i-begin(qbins)-1;
}

int dp[1000001];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) dp[i] = INT_MAX;

  for (int i = 1; i <= n; i++) {
    int a = get_max(i);
    for (int j = a; j >= 0; j--) {
      dp[i] = min(dp[i], dp[i-qbins[j]] + 1);
    }
  }

  cout << dp[n] << endl;
  while (n) {
    int a = get_max(n);
    for (int i = a; i >= 0; i--) {
      if (dp[n] == dp[n-qbins[i]]+1) {
        cout << qbins[i] << ' ';
        n -= qbins[i];
        break;
      }
    }
  }
  cout << endl;
  return 0;
}

