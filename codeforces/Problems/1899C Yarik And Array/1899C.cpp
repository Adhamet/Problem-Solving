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
		int n;
		cin >> n;
		vector<ll> c(2, -1e15);

		ll ans = -1e15;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;

			bool dv = (x % 2 + 2) % 2;
			c[dv] = max(x, c[!dv] + x);
			c[!dv] = -1e15;

			ans = max({ans, c[dv], c[!dv]});
		}
		cout << ans << el;
	}

	return 0;
}


