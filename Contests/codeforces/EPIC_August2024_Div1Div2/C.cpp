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
		int n;
		cin >> n;

		vector<pll> pts(n);
		for (auto &p: pts) cin >> p.first >> p.second;

		ll xs, ys, xt, yt;
		cin >> xs >> ys >> xt >> yt;

		ll dist = abs(xs - xt) * abs(xs - xt) + abs(ys - yt) * abs(ys - yt);

		bool deny = false;
		for (const auto &p: pts) {
			ll cx = abs(p.first - xt);
			ll cy = abs(p.second - yt);

			if (dist >= (cx * cx + cy * cy)) {
				deny = true;
				break;
			}
		}

		if (!deny) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
