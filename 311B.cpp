#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int pots[2000001];

int main() {
  int n, w; cin >> n >> w;
  for (int i = 0; i < 2*n; i++) cin >> pots[i];
  sort(pots, pots+2*n);

  double x1 = pots[n-1], x2 = pots[n] / 2.0;
  double x = min(min(x1, x2), (double) pots[0]);

  cout << fixed << setprecision(20) << min((double) w, x*n + (2.0*x)*n) << endl;

  return 0;
}
