#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool grids[100][12];

bool can_win(int b, int a, int game) {
  int m = a;
  for (int i = 0; i < a; i++) {
    int match = 0;
    for (int j = i; j < 12; j += a) {
      // cout << j << ' ';
      if (grids[game][j]) match++;
    }
    if (match == b) return true;
  }
  // cout << endl;
  return false;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string c;
    cin >> c;
    for (int j = 0; j < 12; j++)
      grids[i][j] = c[j]=='X';
  }

  int nums[] = {1,2,3,4,6,12};


  for (int j = 0; j < n; j++) {
    vector<string> ans;
    for (int i = 0; i < 6 ; i++) {
      int a = nums[i];
      int b = nums[5-i];
      stringstream s;
      s << a << 'x' << b;
      // cout << a << ' ' << b << endl;
      if (can_win(a,b,j)) ans.push_back(s.str());
    }
    cout << ans.size() << ' ';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << endl;
  }
}

