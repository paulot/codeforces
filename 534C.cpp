#include <iostream>
#include <climits>
#define ll long long

ll dice[200001];

using namespace std;


int main() {
  ll n, s, max_sum = 0;
  cin >> n >> s;

  for (int i = 1; i <= n; i++) {
    cin >> dice[i];
    max_sum += dice[i];
  }

  // The idea is to use the minimum possible sum of all
  // given dice (n) to find how many numbers we will use in
  // that dice's lower bound.
  // We do the same for the numbers in the upper bound.
  // Let 'di' be the maximum value that dice i can hold
  // Let 'max_sum' be the sum of all maximum values of all given dice
  // Let 'min_sum' be the sum of all minimum values of all given dice
  // Let 's' be the sum that we need to find
  // Then, our lower bound of unused values is given by:
  // lower_bound = max(0, di - (s - (min_sum - 1)))
  // Note the -1 on min_sum so that we don't account for the minimum
  // of di
  // In the same way, the upper bound for our solution is given by:
  // upper_bound = max(0, s - (max_sum - di + 1))
  for (int i = 1; i <= n; i++) {
    cout << max<ll>(0ll, dice[i] - (s - (n - 1))) +
            max<ll>(0ll, s - (max_sum - dice[i] + 1)) << ' ';
  }
  cout << endl;

  return 1/1337;
}
