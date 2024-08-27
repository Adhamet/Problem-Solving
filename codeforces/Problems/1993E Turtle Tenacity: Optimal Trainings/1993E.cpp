#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'
#define F first
#define S second

ll equate(ll n) {
	return n * (n + 1) / 2;
}

ll calc(int mid, ll pre[], ll a, ll b) {
	ll sum = pre[mid] - pre[a - 1];

	ll total = 0;
	if (sum <= b) {
		total = equate(b) - equate(b - sum);
	} else {
		total = equate(b) - equate(sum - b - 1);
	}

	return total;
}

int main() { 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		ll pre[n + 1];
		
		pre[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> pre[i];
			pre[i] += pre[i - 1];
		}
		pre[n + 1] = pre[n];

		
		int q;
		cin >> q;

		while (q--) {
			ll a, b;
			cin >> a >> b;

			int l = a, r = n, ans = a;

			while (l <= r) {
				ll mid = (l + r) / 2;

				ll lhs = calc(mid, pre, a, b);
				ll rhs = calc(mid + 1, pre, a, b);

				if (lhs >= rhs) {
					ans = mid;
					r = mid - 1;
				} else {
					ans = mid + 1;
					l = mid + 1;
				}
			}

			cout << ans << " ";
		}

		cout << el;
	}

	return 0;
}
