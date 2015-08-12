#include <iostream>
#include <cmath>
#include <map>
#include <iomanip>
#define ll unsigned long long
#define sq(x) ((x)*(x))

using namespace std;

map<ll, ll> counts;

int main() {
  ios::sync_with_stdio(false);
  int n; ll pop;
  cin >> n >> pop;
  for (int i = 0; i < n; i++) {
    int x,y,p; cin >> x >> y >> p;
    counts[sq(x)+sq(y)] += p;
  }
  for (auto &it : counts) {
    if (pop+it.second >= 1000000) {
      cout << fixed << setprecision(7) << sqrt(it.first) << endl;
      return 0;
    }
    pop += it.second;
  }
  cout << -1 << endl;
  return 0;
}
