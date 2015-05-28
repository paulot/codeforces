#include <iostream>
#define ll long long

using namespace std;

ll dp[101][101] = {{0}};

int main() {
  int n, k, d;
  cin >> n >> k >> d;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < k; j++) {
      dp[i][j] += 

