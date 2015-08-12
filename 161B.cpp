#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <iomanip>
#define pb push_back

using namespace std;

typedef pair<int, int> ii;

bool pc(const ii &fe, const ii &se) { return fe.first < se.first; }

int n, k, hs = 0;
vector<ii> items[3];
vector<ii> carts[1001];

double get_price() {
  double ans = 0;
  for (int c = 0; c < hs; c++) {
    int m = INT_MAX;
    double total = 0;
    for (int i = 0; i < carts[c].size(); i++) {
      m = min(m, carts[c][i].first);
      total += carts[c][i].first;
    }
    total -= m;
    total += m/2.0;
    ans += total;
  }
  for (int c = hs; c < k; c++) {
    for (int i = 0; i < carts[c].size(); i++) {
      ans += carts[c][i].first;
    }
  }
  return ans;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    items[b].pb(make_pair(a, i+1));
  }

  sort(items[1].begin(), items[1].end(), pc);
  sort(items[2].begin(), items[2].end(), pc);


  int cart = 0;
  for (int i = items[1].size()-1; i >= 0 and cart < k; i--) {
    carts[cart++].pb(items[1][items[1].size()-1]);
    items[1].pop_back();
  }

  if (cart == k) {
    while (items[1].size() > 0) {
      carts[k-1].pb(items[1][items[1].size()-1]);
      items[1].pop_back();
    }
  }
  hs = cart;
  
  // Add to the cart everything that is bigger than the stool
  for (int c = 0; c < k; c++) {
    int m = 0;
    if (carts[c].size())
      m = carts[c][0].first;

    while (items[2].size() >= k-c and items[2][items[2].size()-1].first >= m) {
      carts[c].pb(items[2][items[2].size()-1]);
      items[2].pop_back();
    }
  }

  // If we still have items left in items[2]
  if (items[2].size() > 0) {
    for (int i = 0; i < items[2].size(); i++) carts[k-1].pb(items[2][i]);
  }

  cout << fixed << setprecision(1) << get_price() << endl;
  for (int i = 0; i < k; i++) {
    cout << carts[i].size() << ' ';
    for (int j = 0; j < carts[i].size(); j++) {
      cout << carts[i][j].second;
      if (j == carts[i].size()-1) cout << endl;
      else cout << ' ';
    }
  }

  return 0;
}
