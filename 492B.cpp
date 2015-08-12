#include <iostream>
#include <algorithm>
#include <iomanip>
#define ll unsigned long long

using namespace std;

ll lan[1000], n, l;

bool check(ll d) {
  // cout << lan[n-1]+d << endl;
  if (not (lan[0] <= d and lan[n-1]+d >= l)) {
    return false;
  }
  // cout << lan[n-1]-lan[0] << ' ' << 2*d << endl;
  if (n == 2 and (not (lan[n-1]-lan[0] < 2*d))) {
    return false;
  }

  for (int i = 1; i < n-1; i++) {
      if (lan[i]-lan[i-1] > 2*d or lan[i+1]-lan[i] > 2*d) {
        return false;
      }
  }
  return true;
}


int main() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> lan[i];
    lan[i] *= 1e9;
  }
  l *= 1e9;

  sort(lan, lan+n);

  ll high = l, low = 0;
  while (high > low) {
    // cout << low << ' ' << high << endl;
    ll mid = (high+low)/2;

    if (check(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << fixed << setprecision(9) << high/(1e9) << endl;
  return 0;
}
  
