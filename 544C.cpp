#include <iostream>

using namespace std;

int dp[501][501];

// For this problem we want to find the total number of ways that the
// equation v1+v2+...+vn=m such that v1a1+v2a2+...+vnan<=b
// More formally this can be expressed as the number of ways
// such that sum(vi) == m under the constraint of  sum(viai) <= b
// 
// The strategy is as follows:
// First we create a table dp of size 500x500. dp[i][j] represents the number of
// ways that we can find a solutions to the above equation for a given number 
// of bugs per line for i lines and forming j total bugs. Then, the sum of the
// ith row of our table will represent the total number of ways to reach b or
// less bugs.
int main() {
  int n, m, b, mod;
  cin >> n >> m >> b >> mod;
  dp[0][0] = 1;

  for (int i = 0; i < n; i++) {
    int bpl; // bugs per line
    cin >> bpl;
    for (int line = 1; line <= m; line++) {
      for (int cbug = bpl; cbug <= b; cbug++) {
        dp[line][cbug] += dp[line-1][cbug-bpl];
        dp[line][cbug] %= mod;
      }
    }
  }

  unsigned int a = 0;
  for (int i = 0; i <= b; i++) { a += dp[m][i]; a %= mod; }
  cout << dp[m][b] << endl;

  return 0;
}
