#include <iostream>
#define endl '\n'

using namespace std;

char grid[501][501];
int h, w, q, dp[501][501], a, b, c, d;

int main() {
  ios_base::sync_with_stdio(false);

  cin >> h >> w;
  for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) cin >> grid[i][j];

  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++) {
      dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
      if (grid[i][j] == '.' and grid[i-1][j] == '.') dp[i][j]++;
      if (grid[i][j] == '.' and grid[i][j-1] == '.') dp[i][j]++;
    }

  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> a >> b >> c >> d;
    int shared = 0;
    for (int j = a; j <= c; j++) if (grid[j][b] == '.' and grid[j][b-1] == '.') shared++;
    for (int j = b; j <= d; j++) if (grid[a][j] == '.' and grid[a-1][j] == '.') shared++;

    cout << dp[c][d] + dp[a-1][b-1] - dp[c][b-1] - dp[a-1][d] - shared << endl;
  }

  return 0;
}

