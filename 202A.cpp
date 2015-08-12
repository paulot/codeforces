#include <cstdio>

using namespace std;

int let[30];

int main() {
  char c, t = 0;
  while ((c = getchar()) != '\n') {
    let[c-'a']++;
    if (c > t) t = c;
  }
  while(let[t-'a']--) putchar(t);
  putchar('\n');
  return 0;
}

