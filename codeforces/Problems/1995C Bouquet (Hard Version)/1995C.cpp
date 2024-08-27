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
		ll n, m;
		cin >> n >> m;
		
		pair<ll, ll> p[n];
		for (int i = 0; i < n; i++) cin >> p[i].first;
		for (int i = 0; i < n; i++) cin >> p[i].second;

		sort(p, p + n);

		ll maxCost = 0;
		for (int i = 0; i < n; i++) {
			int val = min(m / p[i].F, p[i].S);
	
			maxCost = max(maxCost, val * p[i].F);
		}

		for (int i = 0; i < n - 1; i++) {
			if (p[i].F + 1 != p[i + 1]. F) continue;

			ll curr = m;

			ll l = min(curr / p[i].F, p[i].S);
			curr -= l * p[i].first;

			ll r = min(curr / p[i + 1].F, p[i + 1].S);
			curr -= r * p[i + 1].first;

			ll x = min({l, p[i + 1].S - r, curr});
			curr -= x;

			maxCost = max(maxCost, m - curr);
		}

		cout << maxCost << el;
	}

	return 0;
}

