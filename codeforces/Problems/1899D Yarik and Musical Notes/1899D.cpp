#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n;

		map<ll, ll> mp;
		for (int i = 0; i < n; i++) {
      cin >> x;
      mp[x] += 1;
		}

		ll ans = mp[1] * mp[2];
		for (auto [_,x]: mp) ans += (x * (x - 1)) / 2;
		cout << ans << el;
	}

	return 0;
}
