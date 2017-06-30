#include <cstdio>
#include <iostream>
#define ll long long

using namespace std;

int get() {
  int c = getchar();
  while (c <= 32) c = getchar();
  int ret = 0;
  while (c > 32) {
    ret = ret * 10 + c - '0';
    c = getchar();
  } 
  return ret;
}

int a, b, n, l, t, m;

ll getSum(ll n) {
  return (n-l+1)*a+(((ll)l+n)*(n-l+1)/2.0-(n-l+1))*((ll)b);
}

int main() {
  a = get(), b = get(), n = get();
  for (int i = 0; i < n; i++) {
    l = get(), t = get(), m = get();
    // cout << a+(l-1)*b << ' ' <<  t << endl;
    if (a+(l-1)*((ll)b) > t) {
      cout << -1 << endl;
      continue;
    }

    ll high = m*((ll)t), low = l;
    while (high > low) {
      ll mid = (high+low)/2;
      if (a+(mid-1)*((ll)b) <= t) {
        //cout << mid << ' ' << getSum(mid) << endl;
        ll sum = getSum(mid);
        if (sum ==  m*((ll)t)) {
          high = mid+1;
          break;
        } else if (sum > m*((ll)t)) {
          high = mid;
        } else {
          low = mid+1;
        }
      } else {
        high = mid;
      }
    }
    cout << ((high == l) ? high : high-1) <<  endl;
  }
  return 0;
}
