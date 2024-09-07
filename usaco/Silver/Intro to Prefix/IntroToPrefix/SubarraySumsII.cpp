// CSES
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

	int n, x;
	cin >> n >> x;

	vector<int> vec(n);

	for (auto &i: vec) cin >> i;

	map<ll, int> sum;
	sum[0] = 1;

	ll ans = 0, pref = 0;
	for (auto ele: vec) {
		pref += ele;

		ans += sum[pref];

		if (pref % x == 0) sum[pref] += 1;
	}
	cout << ans << el;

	return 0;
}
