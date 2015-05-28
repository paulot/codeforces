#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int n, k;
map<int, vector<int>> graph;

int bfs() {


int main() {
  int a, b;
  cin >> n >> k;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
  }



