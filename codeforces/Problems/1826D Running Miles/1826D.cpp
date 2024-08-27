#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 2e5+10;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		vector<ll> b(n), l(n), r(n);

		for (int i = 0; i < n; i++) {
			cin >> b[i];

			l[i] = b[i] + i;
			r[i] = b[i] - i;
		}

		for (int i = 1; i < n; i++) l[i] = max(l[i], l[i - 1]);
		for (int i = n - 2; i >= 0; i--) r[i] = max(r[i], r[i + 1]);

		ll ans = 0;
		for (int i = 1; i < n - 1; i++) {
			ans = max(ans, l[i - 1] + b[i] + r[i + 1]);
		}

		cout << ans << el;
	}
	
	return 0;
}
