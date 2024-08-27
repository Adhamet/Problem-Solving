#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int n;
ll ans = 0;
vector<pi> cows(n);

ll search() {
	sort(cows.begin(), cows.end());

	auto upd = [&](pair<int, int> a, int b) -> pi {
		return {min(a.F, b), max(a.S, b)};
	};

	vector<pi> pref(n), suff(n);

	pref[0] = {cows[0].S, cows[0].S};
	for (int i = 1; i < n; i++) pref[i] = upd(pref[i - 1], cows[i].S);

	suff[n - 1] = {cows[n - 1].S, cows[n - 1].S};
	for (int i = n - 2; i >= 0; i--) suff[i] = upd(suff[i + 1], cows[i].S);

	ll best = LLONG_MAX;
	ll area = (ll)(cows.back().F - cows.front().F) * (pref.back().S - pref.back().F);
	for (int i = 0; i < n - 1; i++) {
		if (cows[i].F != cows[i].S) {
			ll fRec = (ll)(cows[i].F - cows[0].F) * (pref[i].S - pref[i].F);
			ll sRec = (ll)(cows.back().F - cows[i + 1].F) * (suff[i + 1].S - suff[i + 1].F);

			best = min(best, fRec + sRec);
		}
	}

	return area - best;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);

	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);

	cin >> n;
	cows.resize(n);

	for (auto& c: cows) cin >> c.F >> c.S;
	ans = max(ans, search());

	for (auto& c: cows) swap(c.F, c.S);
	ans = max(ans, search());

	cout << ans << el;
	
	return 0;
}
