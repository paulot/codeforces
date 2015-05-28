#include <iostream>
#include <map>
#define ll unsigned long long

using namespace std;

int nums[100001], qs[100001], dp[100001];

class dict {
  map<int, int> m;
  public:
    void decrement(int);
    void increment(int);
    int len();
};

void dict::decrement(int n) {
  if (m.find(n) != m.end()) {
    m[n]--;
    if (m[n] == 0) {
      m.erase(n);
    }
  }
}

void dict::increment(int n) {
  if (m.find(n) == m.end()) {
    m[n] = 0;
  }
  m[n]++;
}

int dict::len() {
  return m.size();
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  for (int i = 0; i < m; i++)
    cin >> qs[i];

  // Put in dict
  dict d;
  for (int i = 0; i < n; i++) {
    d.increment(nums[i]);
  }
  for (int i = 0; i < n; i++) {
    dp[i] = d.len();
    d.decrement(nums[i]);
  }
  for (int i = 0; i < m; i++)
    cout << dp[qs[i]-1] << endl;
}

