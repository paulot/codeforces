#include <iostream>
#define ll unsigned long long

using namespace std;

ll C[1001][1001];
int N = 1000, K = 1000, mod = 1000000007, n, total = 0, cur, ans = 1;

int main() {
  ios_base::sync_with_stdio(false);
  for (int n = 0; n <= N; n++) C[n][0] = 1;
  for (int n = 0; n <= N; n++) C[n][n] = 1;

  for (int n = 1; n <= N; n++)
    for (int k = 1; k <= K; k++)
      C[n][k] = (C[n-1][k-1] + C[n-1][k]) % mod;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> cur; total += cur;
    ans = (ans * C[total-1][cur-1]) % mod;
  }

  cout << ans << '\n';

  return 0;
}
