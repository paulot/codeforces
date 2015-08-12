#include <iostream>
#include <algorithm>
#define ll unsigned long long

using namespace std;

ll arr[100001], n, m;

int main() {
  ios::sync_with_stdio(false);
  int t, d, q;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> t >> d;
    arr[i] = arr[i-1] + t*d;
  }

  for (int i = 0; i < m; i++) {
    cin >> q;
    cout << lower_bound(arr+1, arr+n+1, q) - arr << endl;
  }
  return 0;
}


