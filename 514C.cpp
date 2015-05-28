#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define ll long long

using namespace std;

set<size_t> hashes;
hash<string> str_hash;
bool ans[500001] = {0};

bool check(string &str, int pos, char c) {
  char t = str[pos];
  str[pos] = c;
  bool a = hashes.find(str_hash(str)) != hashes.end();
  str[pos] = t;
  return a;
}

int main() {
  int m, n;
  cin >> n >> m;
  string in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    hashes.insert(str_hash(in));
  }

  for (int i = 0; i < m; i++) {
    cin >> in;
    for (int j = 0; j < in.size() and not ans[i]; j++) {
      if (in[j] == 'a' and (check(in, j, 'b') or check(in, j, 'c'))) {
        ans[i] = true;
      } else if (in[j] == 'b' and (check(in, j, 'a') or check(in, j, 'c'))) {
        ans[i] = true;
      } else if (in[j] == 'c' and (check(in, j, 'a') or check(in, j, 'b'))) {
        ans[i] = true;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (ans[i]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
