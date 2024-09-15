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

	ll n;
	cin >> n;

	ll l = 1, r = n * n, leq = 0;
	while (l < r) {
		ll mid = (l + r) / 2;
		leq = 0;

		for (int i = 1; i <= n; i++) leq += min(n, mid / i);

		if (leq >= (n * n + 1) / 2) r = mid;
		else l = mid + 1;
	}

	cout << r << el;
	
	return 0;
}
