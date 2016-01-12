#include <iostream>

using namespace std;

int v1, v2, t, d;

int main() {
  cin >> v1 >> v2 >> t >> d;
  int dist = v2;

  for (int i = 1; i < t; i++) {
    dist += v1;
    
    // Can increase a total of d
    if (v1 - d*(t-i) < v2) v1 += min(d, v2+d*(t-(i+1))-v1);
    else v1 -= d;
  }
  cout << dist << '\n';
  return 0;
}
