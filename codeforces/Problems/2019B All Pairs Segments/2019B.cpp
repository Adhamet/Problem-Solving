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

	int t;
	cin >> t;

	while (t--) {
		int n, q;
		cin >> n >> q;

		vector<int> a(n);
		for (auto &i: a) cin >> i;

		map<ll, ll> ans;
		for (int i = 0; i < n; i++) {
			ll cnt = (ll)i * (n - i) + (n - i - 1);
			ans[cnt] += 1;

			if (i > 0) {
				ans[(ll)i * (n - i)] += (a[i] - a[i - 1] - 1);
			}
		}

		while (q--) {
			ll k;
			cin >> k;
			cout << ans[k] << " ";
		}
		cout << el;
	}

	return 0;
}
