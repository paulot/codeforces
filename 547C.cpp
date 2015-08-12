#include <iostream>
#include <map>

using namespace std;

int pairs = 0;
int n, q;
bool sel[200001];
int nums[200001];

bool gcd1(int a, int b) {
  while (b) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a == 1;
}

void unselect(int a) {
  // cout << "unselecting\n";
  for (int i = 0; i < n; i++) {
    if (sel[i] and i != a) {
      bool gcd = gcd1(nums[i], nums[a]);
      if (gcd) pairs--;
    }
  }
  sel[a] = false;
}

void select(int a) {
  // cout << "selecting\n";
  for (int i = 0; i < n; i++) {
    if (sel[i] and i != a) {
      bool gcd = gcd1(nums[i], nums[a]);
      if (gcd) pairs++;
    }
  }
  sel[a] = true;
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> nums[i];

  for (int i = 0; i < q; i++) {
    int cq;
    cin >> cq;
    cq--;
    if (sel[cq]) unselect(cq);
    else select(cq);
    cout << pairs << endl;

    /*
    for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      cout << dp[a][b] << ' ';
    } cout << endl; }
    */
  }

  return 0;
}
