#include <string>
#include <stack>
#include <iostream>
using namespace std;

stack<int> s;
int dp[1000001];

int main() {
  string str;
  cin >> str;
  int size = 0, num = 1, sum = 0, csize = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(') s.push(i);
    else if (not s.empty()) {
      int j = s.top();
      int csize = (i-j)+1;
      s.pop();
      dp[i] = csize + ((j) ? dp[j-1] : 0);
      if (dp[i] == size) num++;
      else if (dp[i] > size) size = dp[i], num = 1;
    }
  }
  cout << size << ' ' << num << endl;

  return 0;
}
