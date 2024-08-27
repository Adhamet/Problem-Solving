#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);

	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	
	ll n, m, r;
	cin >> n >> m >> r;

	vector<ll> cow(n);
	for (auto &i: cow) cin >> i;

	vector<pll> store(m);
	for (auto &i: store) cin >> i.S >> i.F;

	vector<ll> rent(r);
	for (auto &re: rent) cin >> re;

	sort(cow.begin(), cow.end(), greater<ll>());
	sort(store.begin(), store.end(), greater<pll>());
	sort(rent.begin(), rent.end(), greater<ll>());

	vector<ll> val(n);

	int cIdx = 0, sIdx = 0;
	while (cIdx < n && sIdx < m) {
		if (store[sIdx].second > cow[cIdx]) {
			val[cIdx] += cow[cIdx] * store[sIdx].first;
			store[sIdx].second -= cow[cIdx];
			cIdx += 1;
		} else {
			cow[cIdx] -= store[sIdx].second;
			val[cIdx] += store[sIdx].second * store[sIdx].first;
			sIdx += 1;
		}
	}

	sort(val.begin(), val.end());

	ll ans = 0;
	for (int i = 0; i < r && i < n; i++) val[i] = max(val[i], rent[i]);
	for (int i = 0; i < n; i++) ans += val[i];
	cout << ans << el;

	return 0;
}
