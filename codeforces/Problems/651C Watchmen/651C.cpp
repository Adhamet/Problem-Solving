#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define fi first
#define se second
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll n, x, y;
	cin >> n;
	map<ll, ll> freq1, freq2;
	map<pair<ll, ll>, ll> freqpr;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		freq1[x] += 1, freq2[y] += 1;
		freqpr[make_pair(x, y)] += 1;
	}

	ll ans = 0;
	for (auto &i: freq1) ans += ((i.se) * (i.se - 1)) / 2;
	for (auto &i: freq2) ans += ((i.se) * (i.se - 1)) / 2;
	for (auto &i: freqpr) ans -= ((i.se) * (i.se - 1)) / 2;
	cout << ans << el;
	return 0;
}
