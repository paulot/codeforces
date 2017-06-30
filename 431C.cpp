#include <iostream>
#define mod 1000000007

using namespace std;

int dp[101][101], n, k, d;

int main() {
  for (int i = 0; i < 101; i++) dp[0][i] = dp[1][i] = 1;

  for (int i = 2; i < 101; i++)
    for (int k = 1; k < 101; k++)
      for (int j = max(0, i-k); j < i; j++) dp[i][k] = (dp[i][k] + dp[j][k]) % mod;

  cin >> n >> k >> d;
  cout << ((n == d) ? 1 : (dp[n][k] - dp[n][d-1] + mod)) % mod << endl;

  return 0;
}
