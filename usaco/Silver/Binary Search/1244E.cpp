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

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll n, k;
	cin >> n >> k;

	vector<ll> a(n), pref(n + 2);
	for (auto &i: a) cin >> i;
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

	auto can = [&](int X) {
		for (int lp = 0; lp < n; lp++) {
			int rp = upper_bound(a.begin(), a.end(), a[lp] + X) - a.begin();
			ll steps = (ll)lp*a[lp] - pref[lp] + pref[n] - pref[rp] - (ll)(n - rp) * (a[lp] + X);
			if (steps <= k) return true;
		}

		for (int rp = 0; rp < n; rp++) {
			int lp = lower_bound(a.begin(), a.end(), a[rp] - X) - a.begin();
			ll steps = (ll)lp*(a[rp] - X) - pref[lp] + pref[n] - pref[rp] - (ll)(n - rp) * a[rp];
			if (steps <= k) return true;
		}

		return false;
	};

	int l = 0, r = 1e9;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (can(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << el;
	return 0;
}
