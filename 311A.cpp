#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int min1, max1;
  int min2, max2;
  int min3, max3;
  cin >> min1 >> max1;
  cin >> min2 >> max2;
  cin >> min3 >> max3;

  max1 = min(max1, n - min2 - min3);
  max2 = min(max2, n - min1 - min3);

  for (int t1 = max1; t1 >= min1; t1--)
  for (int t2 = max2; t2 >= min2; t2--) {
    int t3 = n - t1 - t2;
    if (t3 >= min3 and t3 <= max3) {
      cout << t1 << ' ' << t2 << ' ' << t3 << endl;
      return 0;
    }
  }
  
}

