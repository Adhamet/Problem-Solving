#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;

vector<ll> ind;
ll compress(ll val) {
	return lower_bound(begin(ind), end(ind), val) - begin(ind);	
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);

	ll n, q;
	cin >> n >> q;

	vector<array<ll, 3>> updates(n);
	for (int i = 0; i < n; i++) {
		int l, r, w;
		cin >> l >> r >> w;

		ind.push_back(l), ind.push_back(r);
		updates[i] = {l, r, w};
	}

	vector<array<ll, 2>> queries(q);
	for (int i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		ind.push_back(l), ind.push_back(r);
		queries[i] = {l, r};
	}

	sort(begin(ind), end(ind));
	ind.erase(unique(ind.begin(), ind.end()), ind.end());

	vector<ll> diff(ind.size() + 2);
	for (auto upt: updates) {
		diff[compress(upt[0]) + 1] += upt[2];
		diff[compress(upt[1]) + 1] -= upt[2];
	}

	for (ll i = 1; i <= ind.size() + 1; i++) diff[i] += diff[i - 1];

	vector<ll> pref(ind.size() + 1);
	for (ll i = 1; i < ind.size(); i++) pref[i] = pref[i - 1] + (diff[i] * (ind[i] - ind[i - 1]));

	for (auto q: queries) cout << pref[compress(q[1])] - pref[compress(q[0])] << el;

	return 0;
}
