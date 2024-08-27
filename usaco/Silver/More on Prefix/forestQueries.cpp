#include <bits/stdc++.h>
using namespace std;
 
#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'
 
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout.tie(0);
 
  int n, q;
  cin >> n >> q;
 
  vector<vector<ll>> pref(n + 2, vector<ll>(n + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char x;
      cin >> x;
 
      if (x == '*')
        pref[i][j] += 1;
      pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }
 
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
 
    cout << pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] +
                pref[x1 - 1][y1 - 1]
         << el;
  }
 
  return 0;
}
