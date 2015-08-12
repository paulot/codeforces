#include <iostream>

using namespace std;

int len[100000], n, m;

bool check(int num) {
  int cs = 0, ms = 0;
  for (int i = 0; i < num; i++) cs += len[i];
  // cout << cs << endl;
  if (cs <= m) return true;

  for (int i = num; i < n; i++) {
    // cout << cs << endl;
    cs -= len[i-num];
    cs += len[i];
    if (cs <= m) return true;
  }
  return false;
}

int main() {
  cin >> n >> m;
  int s = 1e8;
  for (int i = 0; i < n; i++) {
    cin >> len[i];
    s = min(s, len[i]);
  }
  if (s > m) { cout << 0 << endl; return 0; }

  int l = n+1, r = 0, ans = (s <= m) ? 1 : 0;
  while (l > r) {
    int mid = (l+r)/2;

    // cout << "mid " << mid << endl;
    if (not check(mid)) l = mid;
    else {
      r = mid + 1;
      ans = max(ans, mid);
    }
  }
  cout << ans << endl;
}
