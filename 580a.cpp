#include <iostream>

using namespace std;

int n, arr[1000000];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];

  int start = 1, end = 1, size = 0;
  while (end <= n) {
    while (arr[end] >= arr[end-1] and end <= n) end++;
    size = max(size, end - start);
    start = end++;
  }
  cout << size << endl;
  return 0;
}
