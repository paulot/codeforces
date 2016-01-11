#include <cstdio>
#define mod 1000000007
#define m 100000

using namespace std;

int dp[100005];
int tn, k, a, b;

inline int read() {
  int x = 0 , f = 1 ; char ch = getchar() ;
  for ( ; ch < '0' || ch > '9' ; ch = getchar() ) if ( ch == '-' ) f = -1 ;
  for ( ; ch >= '0' && ch <= '9' ; ch = getchar() ) x = x * 10 + ch - '0' ;
  return x * f ;
}

int main() {
  tn = read(), k = read();
  
  for (int i = 0; i <= m; i++)
    if (i < k) dp[i] = 1;
    else dp[i] = (dp[i - 1] + dp[i - k]) % mod;

  for (int i = 1; i <= m; i++) dp[i] = (dp[i-1] + dp[i]) % mod;

  for (int i = 0; i < tn; i++) {
    a = read(), b = read();
    printf("%d\n", (dp[b] - dp[a-1] + mod) % mod);
  }

  return 0;
}
