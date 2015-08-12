#include <iostream>
#include <set>

using namespace std;

set<int> hor, ver;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  hor.insert(0), hor.insert(h);
  ver.insert(0), ver.insert(w);
  for (int i = 0; i < n; i++) {
    char c; int val; cin >> c >> val;
    if (c == 'H') hor.insert(val);
    else ver.insert(val);

    // int top = 0, bot = ver, left = 0, right = w;

    int max_area = 0;
    for (auto top = hor.begin(), bot = next(top, 1); bot != hor.end(); top++, bot++) {
      // cout << *top << ' ' << *bot << endl;
      for (auto left = ver.begin(), right = next(left, 1); right != ver.end(); left++, right++) {
        max_area = max(max_area, (*bot-*top) * (*right-*left));
      }
    }
    cout << max_area << endl;
  }
  return 0;
}



