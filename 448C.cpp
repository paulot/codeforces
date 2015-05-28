#include <iostream>

using namespace std;

int p[5009];
int n;


// For this problem we want to find the minimum number of ways to paint a fence
// such that we can have vertical or horizontal strokes. The strategy goes as following:
// We know that we can always paint the fence all vertical costing r-l. So the
// cost of painting will be the minimum value between r-l and the cost of painting
// the part at hte left of the fence + the part at the right at the fence.`
int paint(int l, int r, int h) {
  // cout << l << ' ' << r << ' ' << h << endl;
  if (l >= r) return 0;
  int m = l;
  for (int i = l; i < r; i++) if (p[m] > p[i]) m = i;
  return min(r-l, p[m]-h + paint(l, m, p[m]) + paint(m+1, r, p[m]));
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  cout << paint(0, n+1, 0) << endl;

  return 0;
}

