#include <iostream>
#include <cmath>

using namespace std;

int pos[100000], height[100000], m, n;

bool possible() {
  for (int i = 0; i < m-1; i++) {
    if (pos[i+1]-pos[i] < abs(height[i]-height[i+1])) return false;
  }
  return true;
}

int geth(int p1, int h1, int p2, int h2) {
  int h = h1, p = p1;
  while (p < p2 and (p2-p) >= abs(h-h2)) h++, p++;
  h--;
  return max(h2, h);
}


int solve() {
  int mh = (pos[0]-1) + height[0];
  for (int i = 0; i < m-1; i++) {
    mh = max(mh, geth(pos[i], height[i], pos[i+1], height[i+1]));
  }
  return max(mh, (n-pos[m-1]) + height[m-1]);
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> pos[i] >> height[i];

  if (not possible()) { cout << "IMPOSSIBLE" << endl; return 0; }

  cout << solve() << endl;
  return 0;
}
