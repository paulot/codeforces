#include <iostream>


using namespace std;

int h[100005], x[100005], n;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> h[i];
  int fell = 1, last = x[0];
  x[n] = -1, h[n] = 0;

  // Try to fall left, try to fall right
  for (int i = 1; i < n; i++)
    if (x[i]-h[i] > last) fell++, last = x[i];
    else if (x[i]+h[i] < x[i+1] or x[i+1] == -1) fell++, last = x[i]+h[i];
    else last = x[i];

  cout << fell << endl;
  return 0;
}

