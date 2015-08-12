#include <iostream>
#define ll unsigned long long
#define min(a,b) ((a < b) ? a : b)

using namespace std;

ll n, m, k;

inline ll check(ll num) {
  register ll ways = 0;
  for (int i = 1; i <= n; i++) ways += min(num/i, m);
  return ways;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  register ll l = n*m, r = 0, mid;
  while(l > r) {
    mid = (l+r)/2;
    if (check(mid) < k) r = mid+1;
    else l = mid;
  }
  cout << l << endl;
  return 0;
}
