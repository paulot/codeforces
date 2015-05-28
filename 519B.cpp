#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll c1[100001], c2[100001], c3[100001];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c1[i];
  for (int i = 0; i < n - 1; i++)
    cin >> c2[i];
  for (int i = 0; i < n - 2; i++)
    cin >> c3[i];

  sort(c1, c1 + n);
  sort(c2, c2 + n - 1);
  sort(c3, c3 + n - 2);

  for (int i = 0; i < n; i++) {
    if (c1[i] != c2[i]) {
      cout << c1[i] << endl;
      break;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (c2[i] != c3[i]) {
      cout << c2[i] << endl;
      break;
    }
  }

  return 1/1337;
}
