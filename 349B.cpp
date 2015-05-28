#include <iostream>
#include <string>
#include <map>
#define ll unsigned long long

using namespace std;

class bignum {
  ll size = 0;
  ll chars[10] = {0};
  public:
    bignum();
    bignum(char);
    bignum& operator +=(const bignum &);
    bignum& operator =(const bignum &);
    ll len();
    void print();
};

bignum::bignum() {
}

bignum::bignum(char c) {
  chars[c-'0'] = 1;
  size += 1;
}

ll bignum::len() {
  return this->size;
}

bignum& bignum::operator +=(const bignum &other) {
  for (int i = 0; i < 10; i++)
    this->chars[i] += other.chars[i];
  this->size += other.size;
  return *this;
}

bignum& bignum::operator =(const bignum &other) {
  for (int i = 0; i < 10; i++)
    this->chars[i] = other.chars[i];
  this->size = other.size;
  return *this;
}

void bignum::print() {
  for (int i = 9; i >= 0; i--) {
    if (this->chars[i]) {
      for (int j = 0; j < this->chars[i]; j++) {
        cout << i;
      }
    }
  }
  cout << endl;
}


bignum dp[1000001];
ll weight[11] = {0};
string nums = "0123456789";


int main() {
  ll cap;
  cin >> cap;
  for (int i = 1; i < 10; i++)
    cin >> weight[i];

  
  for (int i = 1; i < 10; i++) {
    for (ll w = weight[i]; w <= cap; w++) {
      bignum num(nums[i]);
      if (dp[w - weight[i]].len() != 0)
        num += dp[w - weight[i]];

      if (num.len() >= dp[w].len())
        dp[w] = num;
    }
  }

  if (dp[cap].len() > 0)
    dp[cap].print();
  else
    cout << -1 << endl;
  return 0;
}

