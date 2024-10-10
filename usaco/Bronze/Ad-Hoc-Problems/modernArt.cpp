#include <bits/stdc++.h>
using namespace std;

void setIO(string name) {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}

int n, grid[10][10];

bool colorAppears(int c) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == c)
        return true;
  return false;
}

bool on_top_of(int r1, int r2) {
  int top = n, bottom = 0, left = n, right = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == r2) {
        top = min(top, i);
        bottom = max(bottom, i);
        left = min(left, j);
        right = max(right, j);
      }

  for (int i = top; i <= bottom; i++)
    for (int j = left; j <= right; j++)
      if (grid[i][j] == r1)
        return true;

  return false;
}

int main() {
  setIO("art");

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
      grid[i][j] = s[j] - '0';
  }

  int res = 0;
  for (int i = 1; i <= 9; i++) {
    if (colorAppears(i)) {
      bool couldBeFirst = true;
      for (int j = 1; j <= 9; j++)
        if (j != i && colorAppears(j) && on_top_of(i, j))
          couldBeFirst = false;
      if (couldBeFirst)
        res++;
    }
  }
  cout << res;

  return 0;
}
