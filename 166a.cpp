#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> ii;

map<ii, int> countt;
vector<ii> vals;

struct comp {
  bool operator() (const ii& lhs, const ii& rhs) const{
    if (lhs.first == rhs.first) return lhs.second < rhs.second;
    return lhs.first > rhs.first;
  }
};

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    ii p = make_pair(a,b);
    vals.push_back(p);
    countt[p]++;
  }

  sort(vals.begin(), vals.end(), comp());

  cout << countt[vals[k-1]] << endl;

  return 0;
}


