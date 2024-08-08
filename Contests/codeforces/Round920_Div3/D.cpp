#include <bits/stdc++.h>
#include <cstdlib>
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
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    sort(begin(a), end(a));
    sort(begin(b), end(b));

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans += max(abs(a[i] - b[m - i - 1]), abs(a[i] - b[n - i - 1]));
    }

    cout << ans << el;
  }

  return 0;
}
