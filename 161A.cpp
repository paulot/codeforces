#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef pair<int, int> ii;

bool pc(const ii &fe, const ii &se) { return fe.first < se.first; }

int n, m, x, y;
ii solds[100001], vests[100001];

bool fits(ii &vest, ii &sold) {
  return sold.first-x <= vest.first 
    and sold.first+y >= vest.first;
}

int main() {
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    solds[i] = make_pair(a, i+1);
  }
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    vests[i] = make_pair(a, i+1);
  }

  sort(solds, solds+n, pc);
  sort(vests, vests+m, pc);

  int a = 0, b = 0;
  vector<string> ans;
  while (b < m and a < n) {
    if (fits(vests[b], solds[a])) {
      stringstream sstm;
      sstm << solds[a++].second << ' ' << vests[b++].second;
      ans.push_back(sstm.str());
    } else if (vests[b].first > solds[a].first) a++;
    else b++;
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  

  return 0;
}


