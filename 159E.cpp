#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
#include <vector>
#define ll unsigned long long

using namespace std;

template<int M, template<typename> class F = greater>
struct TupleCompare {
  template<typename T>
  bool operator()(T const &t1, T const &t2) {
    return F<typename tuple_element<M, T>::type>()(std::get<M>(t1), std::get<M>(t2));
  }
};

typedef std::map<ll, vector<tuple<ll,ll> > >::iterator it_type;

// Form a dp of color and sum of height, summed from reverse sort.
class dict {
  map<ll, vector<tuple<ll, ll> > > indexes;
  int index = 0;
  public:
    void add_box(ll, ll, ll);
    void solve();
    void print();
  private:
    void sort_map();
    void sum_up();
    void prune(int);

};

void dict::add_box(ll color, ll size, ll ind) {
  indexes[color].push_back(tuple<ll, ll>(size, ind));
}

void dict::sort_map() {
  for (auto& box : indexes) {
    sort(begin(box.second), end(box.second), TupleCompare<0>());
  }
}

void dict::print() {
  for (auto& box : indexes) {
    for (int i = 0; i < box.second.size(); i++)
      cout << get<0>(box.second[i]) << " ";
    cout << endl;
  }
}

void dict::sum_up() {
  for (auto& box : indexes)
    for (int i = 1; i < box.second.size(); i++)
      get<0>(box.second[i]) += get<0>(box.second[i-1]);
}

void dict::prune(int size) {
  it_type gmax1 = indexes.end();
  it_type gmax2 = indexes.end();

  for(it_type i = indexes.begin(); i != indexes.end();) {
    if (i->second.size() == size) {
      // Then we can check the branch
      if (gmax1 == indexes.end())
        gmax1 = i;
      else if (gmax2 == indexes.end()) {
        // Keep gmax1-2 in a sorted order
        if (get<0>(i->second[size-1]) > get<0>(gmax1->second[size-1])) {
          gmax2 = gmax1;
          gmax1 = i;
        } else {
          gmax2 = i;
        }
      } else {
        // Find out if we need to kick out any gmax
        if (get<0>(i->second[size-1]) > get<0>(gmax1->second[size-1])) {
          indexes.erase(gmax2);
          gmax2 = gmax1;
          gmax1 = i;
        } else if (get<0>(i->second[size-1]) > get<0>(gmax2->second[size-1])) {
          indexes.erase(gmax2);
          gmax2 = i;
        } else {
          indexes.erase(i++);
          continue;
        }
      }
    }
    i++;
  }
}

void dict::solve() {
  sort_map();
  sum_up();
  prune(1);
  prune(2);
  prune(3);
  prune(4);
  prune(5);
  prune(6);
  prune(7);
  prune(8);
  prune(9);
  prune(10);

  it_type gmin, gmax;
  ll height = 0;
  int nblocks = 0;
  for(it_type i = indexes.begin(); i != prev(indexes.end()); i++) {
    for(it_type j = next(i); j != indexes.end(); j++) {
      it_type cmin, cmax;

      // Find which it has less block and find possible height
      if (i->second.size() < j->second.size()) {
        cmin = i;
        cmax = j;
      } else {
        cmin = j;
        cmax = i;
      }

      // Find possible height
      int min_ind = cmin->second.size() - 1;
      ll ph = get<0>(cmin->second[min_ind]) + get<0>(cmax->second[min_ind]);
      int cnblocks = cmin->second.size() * 2;

      // Account for the extra block if possible
      if (cmax->second.size() > cmin->second.size()) {
        ph -= get<0>(cmax->second[min_ind]);
        ph += get<0>(cmax->second[min_ind+1]);
        cnblocks += 1;
      }

      // Update the max height and the pointers
      if (ph > height) {
        height = ph;
        gmin = cmin;
        gmax = cmax;
        nblocks = cnblocks;
      }
    }
  }
      
  cout << height << endl; 
  cout << nblocks << endl; 

  // Find out the order that we picked the blocks and print them
  // by index
  for (int i = 0; i < gmin->second.size(); i++) {
    if (i > 0) cout << ' ';
    cout << get<1>(gmax->second[i]) << ' '
         << get<1>(gmin->second[i]);
  }

  // Print out last block if there was any
  if (gmin->second.size() < gmax->second.size())
    cout << ' ' << get<1>(gmax->second[gmin->second.size()]);
  cout << endl;
}


int main() {
  ll n, c, s;
  dict cubes;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c >> s;
    cubes.add_box(c, s, i);
  }
  cubes.solve();
}

