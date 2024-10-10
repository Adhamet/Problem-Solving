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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll n, q;
	cin >> n >> q;

	vector<ll> a(n);
	for (auto &i: a) cin >> i;
	
	vector<ll> pref(n + 2);
	while (q--) {
		int l, r;
		cin >> l >> r;

		pref[l] += 1;
		pref[r + 1] -= 1;
	}

	vector<ll> update(n);
	for (int i = 1; i <= n; i++) {
		pref[i] += pref[i - 1];
		update[i - 1] = pref[i];
	}

	sort(begin(update), end(update));
	sort(begin(a), end(a));

	ll ans = 0;
	for (int i = 0; i < n; i++) ans += a[i] * update[i];
	cout << ans << el;

	return 0;
}	
