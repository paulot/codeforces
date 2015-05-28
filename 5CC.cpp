#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int dp [1001000];
string s;
stack <int> st;

int main ()
{
  cin >> s;
  int len = s.size ();
  for (int i = 0; i <len; i ++)
  {
    if (s [i] == '(')
    {
      st.push (i);
    }
    else
    {
      if (! st.empty ())
      {
        int tmp = st.top ();
        st.pop ();
        if (tmp)
          dp [i] = dp [tmp-1] + i-tmp + 1;
        else
          dp [i] = i-tmp + 1;
      }
    }
  }
  int maxn = -1, cnt = 0;
  for (int i = 0; i <len; i ++)
  {
    if (maxn <dp [i])
    {
      maxn = dp [i];
      cnt = 1;
    }
    else if (maxn == dp [i])
    {
      cnt ++;
    }
  }
  if (maxn == 0)
    cout << "0 1" << endl;
  else
    cout << maxn << " " << cnt << endl;
  return 0;
}
