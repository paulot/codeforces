#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll unsigned long long

using namespace std;

ll n, dp1[100001], dp2[100001];

inline int read() {
  int x = 0 , f = 1 ; char ch = getchar() ;
  for ( ; ch < '0' || ch > '9' ; ch = getchar() ) if ( ch == '-' ) f = -1 ;
  for ( ; ch >= '0' && ch <= '9' ; ch = getchar() ) x = x * 10 + ch - '0' ;
  return x * f ;
}

int main() {
  ios_base::sync_with_stdio(0);
  n = read();
  for (int i = 1; i <= n; i++) dp2[i] = dp1[i] = read();

  sort(dp2, dp2 + n + 1);
  for (int i = 1; i <= n; i++) dp1[i] += dp1[i-1], dp2[i] += dp2[i-1];

  int a, b, c, m = read();
  for (int i = 0; i < m; i++) {
    a = read(), b = read(), c = read();
    if (a == 1) cout << dp1[c] - dp1[b-1] << '\n';
    else if (a == 2) cout << dp2[c] - dp2[b-1] << '\n';
  }
  return 0;
}
