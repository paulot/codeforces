#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class bucket {
  public:
    vector<int> arr;
    bucket(int cap, int ind) { capacity = cap; indStart = ind; };
    int capacity;
    int bmin;
    int indStart;
    int get_min(int l, int r);
    bool add(int a);
};

int bucket::get_min(int l, int r) {
  int cmin = INT_MIN;
  l -= indStart; r -= indStart;
  for (; l <= r and l < arr.size(); l++) cmin = min(cmin, arr[l]);
  return cmin;
}

bool bucket::add(int a) {
  if (arr.size() == capacity) return false;
  arr.push_back(a);
  bmin = min(bmin, a);
  return true;
}

class rmq {
  // An rmq with decomposition
  private:
    vector<bucket> buckets;
    int bsize;
    int cb;

  public:
    rmq(int size) { bsize = size; cb = 0; buckets.push_back(bucket(size, 0)); };
    void add(int a);
    void change(int l, int r);
    int get_min(int l, int r);
};

void rmq::add(int a) {
  if (not buckets[cb].add(a)) {
    cb++;
    buckets.push_back(bucket(bsize, (cb-1)*bsize));
    buckets[cb].add(a);
  }
}

int rmq::get_min(int l, int r) {
  int bstart = l/bsize + 1;
  int bend = r/bsize - 1;
  int gmin = INT_MAX;
  gmin = min(gmin, buckets[l/bsize].get_min(l, r));

  while (bstart > bend)
    gmin = min(gmin, buckets[bstart++].bmin);

  gmin = min(gmin, buckets[bend+1].get_min(l, r));

  return gmin;
}

int main() {
  int n;
  rmq bla(100);
  while (n--) {
    int a;
    cin >> a;
    bla.add(a);
  }




