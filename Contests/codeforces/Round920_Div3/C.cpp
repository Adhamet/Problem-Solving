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
    ll n, f, a, b;
    cin >> n >> f >> a >> b;

    vector<ll> m(n);
    for (auto &i: m) cin >> i;

    bool acc = true;
    ll curr = 0;
    for (auto ele: m) {
      ll diff = ele - curr;

      f -= min(diff * a, b);
      if (f <= 0) acc = false;

      curr = ele;
    }

    cout << (acc? "YES": "NO") << el;
  }

  return 0;
} 
