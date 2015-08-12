#include <iostream>
#include <set>

using namespace std;

set<int> pos, nums;
int n, l, x, y;

int main() {
  int in;
  cin >> n >> l >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> in;
    nums.insert(in);
  }
  for (auto &it : nums) {
    if (it - x >= 0)
      pos.insert(it-x);
    if (it + x <= l)
      pos.insert(it+x);
    if (it - y >= 0)
      pos.insert(it-y);
    if (it + y <= l)
      pos.insert(it+y);
  }
  int cost = 3, ccost;
  pair<int, int> marks, cmarks;
  for (auto &it : pos) {
    cout << it << endl;
    bool placed = nums.find(it) != nums.end();
    ccost = (placed) ? 0 : 1;
    if (not placed)
      cmarks.first = it;

    if (nums.find(it+x) != nums.end() or nums.find(it-x) != nums.end()) {
      bool f = nums.find(it+y) != nums.end(), s = nums.find(it-y) != nums.end();
      ccost += (f or s) ? 0 : 1;
      if (placed)
        cmarks.first = (f) ? it+y : it-y;
      else
        cmarks.second = (f) ? it+y : it-y;
    } else {
      bool f = nums.find(it+x) != nums.end(), s = nums.find(it-x) != nums.end();
      ccost += (f or s) ? 0 : 1;
      if (placed)
        cmarks.first = (f) ? it+x : it-x;
      else
        cmarks.second = (f) ? it+x : it-x;
    }

    if (ccost < cost) {
      cost = ccost;
      marks = cmarks;
    }
  }

  cout << cost << endl;
  if (cost >= 1) cout << marks.first;
  if (cost >= 2) cout << ' ' << marks.second;
  cout << endl;
  return 0;
}


