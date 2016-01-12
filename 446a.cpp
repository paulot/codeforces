#include <iostream>

using namespace std;


int starting[100001], ending[100001], arr[100001], n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  m = (n == 2) ? 2 : 1;
  for (int i = 0; i < n; i++) cin >> arr[i];
  starting[n-1] = 1;
  for (int i = n-2; i >= 0; i--) starting[i] = (arr[i] < arr[i+1]) ? starting[i+1] + 1 : 1;
  ending[0] = 1;
  for (int i = 1; i < n; i++) ending[i] = (arr[i] > arr[i-1]) ? ending[i-1] + 1 : 1;
  for (int i = 1; i < n - 1; i++)
    m = max(max(max(ending[i-1] + 1 + ((arr[i+1] - arr[i-1] >= 2) ? starting[i+1] : 0), m), 1 + ending[i-1]), 1 + starting[i+1]);

  m = max(1 + starting[1], m);
  m = max(1 + ending[n-2], m);

  cout << m << '\n';

  return 0;
}
