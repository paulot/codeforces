#include <iostream>

using namespace std;

int C[10000002][100002], N = 1000, K = 1000, mod = 1000000007;

int main() {
  for (int n = 0; n <= N; n++) C[n][0] = 1;
  for (int n = 0; n <= N; n++) C[n][n] = 1;

  for (int n = 1; n <= N; n++)
    for (int k = 1; k <= K; k++)
      C[n][k] = (C[n-1][k-1] + C[n-1][k]) % mod;

  /*
  cout << "{ ";
  for (int n = 0; n <= N; n++) {
    cout << "{ ";
    for (int k = 0; k <= K; k++) {
      if (C[n][k] == 0) break;
      cout << C[n][k] << ',';
    }
    if (n == N) cout << "} };" << endl;
    else cout << "}, " << endl;
  } cout << endl;
  */
}
