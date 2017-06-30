#include <iostream>
#include <map>

using namespace std;


int arr[200001], n, k, b, ways;
map<int, int> counts;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i], counts[arr[i]]++;

  for (int i = 0; i < n; i++) {
    counts[arr[i]]--;
    if (counts[arr[i]] == 0) counts.erase(arr[i]);

    b = arr[i];
    if (counts.find(b*k) != counts.end() and counts.find(b*k*k) != counts.end())
      ways += counts[b*k] * counts[b*k*k];
  }

  cout << ways << '\n';
  return 0;
}





