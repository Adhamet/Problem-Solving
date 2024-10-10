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

	ll n, t;
	cin >> n >> t;

	vector<ll> products(n);
	for (auto &i: products) cin >> i;

	auto can = [&] (ll mid) {
		ll val = 0;
		for (auto &i: products) val += (mid / i);
		return val >= t;
	};

	ll l = 0, r = *min_element(products.begin(), products.end()) * t, ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;

		if (can(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << el;
}
