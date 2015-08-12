#include <iostream>

using namespace std;

bool state[500][500];
int row[500];
int n, m, q;



int maxr(int r) {
  int rm = 0, gm = 0;
  for (int i = 0; i < m; i++) {
    if (state[r][i]) rm++;
    else rm = 0;
    gm = max(gm, rm);
  }
  return gm;
}

int getmax() {
  int ma = 0;
  for (int i = 0; i < n; i++) {
    ma = max(ma, row[i]);
  }
  return ma;
}

int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> state[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    row[i] = maxr(i);
  }

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    state[a][b] = !state[a][b];
    row[a] = maxr(a);
    cout << getmax() << endl;
  }
  return 0;
}
