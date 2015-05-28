#include <iostream>
#include <string>
#include <map>
#include <vector>
#define ll unsigned long long
#define pb push_back
#define getv(i) vals[str[i]-'a']

using namespace std;

ll sumf[100005] = {0};
vector<int> pos[26];
int vals[26];
string str;

int main() {
  for (int i = 0; i < 26; i++) 
    cin >> vals[i];
  
  cin >> str;
  for (int i = 1; i < str.size(); i++) {
    sumf[i] = getv(i-1);
    sumf[i] += sumf[i-1];
  }

  for (int i = 0; i < str.size(); i++)
    pos[str[i]-'a'].pb(i+1);

  ll ways = 0;
  for (int c = 0; c < 26; c++) {
    map<ll, int> num_sums;
    for (int i = 0; i < pos[c].size(); i++) {
      ways += num_sums[sumf[pos[c][i] - 1]];
      num_sums[sumf[pos[c][i]]]++;
    }
    num_sums.clear();
  }

  cout << ways << endl;

  return 1/1337;
}


/*
int sumb[100005] = {0};

  for (int i = str.size()-1; i >= 0; i--)
    sumb[i] += sumb[i+1] + getv(i);
  for (int i = 0; i < str.size(); i++)
    pos[str[i]].pb(i);

  for (auto& cpos : pos)
    for (int i = 1; i < cpos.second.size(); i++)
      ways += (gets(cpos.second[i-1], cpos.second[i]) == 0) ? 1 : 0;

  int total = sumb[0];
  for (int i = 0; i < str.size(); i++) {
    for (int j = i + 1; j < str.size(); j++) {
      if (str[i] != str[j])
        continue;
      if (gets(i, j) == 0)
        ways++;
    }
  }
  */

