#include <algorithm>
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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<ll> a(n);
		for (auto &i: a) cin >> i;

		auto checkMx = [&](ll curr) {
			ll extra = 0;
			for (int i = n - 1; i >= 0; i--) {
				extra += (curr - a[i]);
				if (extra < 0) return false;
			}
			return true;
		};

		auto checkMn = [&](ll curr) {
			ll extra = 0;
			for (int i = 0; i < n; i++) {
				extra += (a[i] - curr);
				if (extra < 0) return false;
			}
			return true;
		};

		ll l = 0, r = *max_element(a.begin(), a.end());
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			
			if (checkMx(mid)) r = mid - 1;
			else l = mid + 1;
		}
		ll minimumMax = l;

		l = 0, r = *max_element(a.begin(), a.end());
		while (l <= r) {
			ll mid = l + (r - l) / 2;

			if (checkMn(mid)) l = mid + 1;
			else r = mid - 1;
		}
		ll maximumMin = r;

		cout << minimumMax - maximumMin << el;
	}

	return 0;
}
