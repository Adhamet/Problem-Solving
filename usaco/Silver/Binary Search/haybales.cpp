#include <algorithm>
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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	setIO("haybales");

	ll n, q;
	cin >> n >> q;

	vector<ll> a(n);
	for (auto &i: a) cin >> i;
	sort(a.begin(), a.end());

	while (q--) {
		ll l, r;
		cin >> l >> r;

		cout << upper_bound(begin(a), end(a), r) - lower_bound(begin(a), end(a), l) << el;
	}

	return 0;
}
