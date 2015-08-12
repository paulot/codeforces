#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int k[500000], kcount[100001];

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    kcount[k[i]]++;
  }

  sort(k, k+n);

  int ans = 0, pos = n-1;
  for (int i = n/2-1; i >= 0; i--) {
    if (k[pos] >= k[i]*2) {
      kcount[k[pos]]--;
      kcount[k[i]]--;
      ans++;
    }

    while(pos > i and kcount[k[pos]] <= 0) pos--;
  }
  cout << n-ans << endl;
}
