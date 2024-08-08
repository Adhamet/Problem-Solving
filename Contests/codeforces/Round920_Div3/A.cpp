#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  
  while (t--) {
    pair<int,int> pts[4];

    for (int i = 0; i < 4; i++) cin >> pts[i].first >> pts[i].second;

    sort(begin(pts), end(pts));

    cout << abs(pts[0].first - pts[2].first) * abs(pts[0].second - pts[1].second) << el;
  }

  return 0;
}
