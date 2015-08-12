#include <iostream>
#include <algorithm>
#define ll unsigned long long

using namespace std;

ll cans[100000], nc, nw;

int main() {
  cin >> nc;
  ll m = 0;
  for (int i = 0; i < nc; i++) {
    int in; cin >> in;
    m += in;
    cans[i] = m;
  }

  cin >> nw;
  for (int i = 0; i < nw; i++) {
    int in; cin >> in;
    cout << (lower_bound(cans, cans+nc, in) - begin(cans)) + 1 << endl;
  }
  return 0;
}

