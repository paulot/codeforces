#include <iostream>
#define ll unsigned long long

using namespace std;

int main() {
  int w, h;
  cin >> w >> h;
  ll ways = 0;

  for (int i = 1; i < h; i += 2) {
    for (int j = 1; j < w; j += 2) {
      ways += (w-j) * (h-i);
    }
  }
  cout << ways << endl;
}
