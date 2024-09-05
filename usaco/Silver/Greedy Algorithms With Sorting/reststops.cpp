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

	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	
	ll len, n, farmer, bessie;
	cin >> len >> n >> farmer >> bessie;

	vector<pll> rest(n);
	for (int i = 0; i < n; i++) cin >> rest[i].F >> rest[i].S;
	sort(rest.begin(), rest.end(), [&](pll a, pll b) {
		if (a.S == b.S) return a.F < b.F;
		return a.S > b.S;
	});

	ll ans = 0, lastB = 0, currX = 0;
	for (int i = 0; i < n; i++) {
		if (rest[i].F < currX) continue;
		ll reachB = bessie * rest[i].F + lastB;
		ll reachF = farmer * rest[i].F;

		ans += (reachF - reachB) * rest[i].S;
		currX = rest[i].F;

		lastB += (reachF - reachB);
	}
	cout << ans;
	
	return 0;
}
