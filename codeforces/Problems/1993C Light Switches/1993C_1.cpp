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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		vector<ll> a(n);
		for (auto &i: a) cin >> i;
		sort(begin(a), end(a));

		for (int i = 0; i < n; i++) {
			ll l = 0, r = 1e9, best;
			
			while (l <= r) {
				ll mid = (l + r) / 2;

				ll currBegin = 2 * (k * mid) + a[i];
				ll currEnd = currBegin + k - 1;

				if (currEnd >= a[n - 1]) {
					best = mid;
					r = mid - 1;
				} else l = mid + 1;
			}

			a[i] = a[i] + (2 * (k * best));
		}

		sort(begin(a), end(a));
		if (a[n - 1] - a[0] + 1 <= k) {
			cout << a[n - 1] << el;
		} else cout << -1 << el;
	}

	return 0;
}
