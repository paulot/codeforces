#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

map<int, int> t1, t2;
set<int> iter;

int main() {
  ios::sync_with_stdio(false);
  int n, m, in; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> in;
    t1[in]++;
    iter.insert(in);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> in;
    t2[in]++;
    iter.insert(in);
  }

  ll t1s = n*3, t2s = m*3;
  ll mt1 = t1s, mt2 = t2s;
  for (auto &it : iter) {
    t1s = (t1s-t1[it]*3+t1[it]*2);
    t2s = (t2s-t2[it]*3+t2[it]*2);
    if (t1s-t2s > mt1-mt2) {
      mt1 = t1s; mt2 = t2s;
    }
  }
  cout << mt1 << ':' << mt2 << endl;
  return 0;
}
