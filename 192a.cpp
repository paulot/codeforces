#include <iostream>
#include <bitset>

using namespace std;

bitset<1000000001> tnums;

int main() {
  int n; cin >> n;
  for (int i = 1; (i*(i+1))/2 < n; i++) tnums[(i*(i+1))/2] = true;
  for (int i = 1; (i*(i+1))/2 < n; i++) {
    // cout << ((i*(i+1))/2) << ' ' << n-((i*(i+1))/2) << endl;
    if (tnums[n-((i*(i+1))/2)]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
