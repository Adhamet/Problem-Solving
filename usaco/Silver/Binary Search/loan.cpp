#include <bits/stdc++.h>
using namespace std;

#define el '\n'
using ll = long long;

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

bool check(ll n, ll m, ll k, ll x) {
	ll g = 0;
	
	while (k > 0 && g < n) {
		ll y = (n - g) / x;
		if (y < m) return ((n - g + m - 1) / m) <= k;

		ll mx = n - x * y;
		ll days = (mx - g) / y + 1;

		if (days > k) days = k;
		
		g += y * days, k -= days;
	}

	return g >= n;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("loan");

	ll n, k, m, l = 1, r = 1e12;
	cin >> n >> k >> m;
	
	while (l < r) {
		ll mid = (l + r + 1) / 2;
		if (check(n, m, k, mid)) l = mid;
		else r = mid - 1;
	}

	cout << l << el;
	return 0;
}
