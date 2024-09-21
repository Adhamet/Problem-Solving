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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<int> a(n), col(n);
	for (auto &i: a) cin >> i;
	for (auto &i: col) cin >> i;

	map<int, vector<ll>> col_prefs;
	for (int i = 0; i < n; i++) {
		int c = col[i];
		if (!col_prefs.count(c)) col_prefs[c] = {0};
		col_prefs[c].push_back(col_prefs[c].back() + a[i]);
	}

	ll tot = 0;
	map<int, ll> col_exclude;

	int q;
	cin >> q;
	while (q--) {
		int type, col;
		ll arg;
		cin >> type >> col >> arg;

		if (type == 1) {
			tot += arg;
			col_exclude[col] += arg;
		} else if (type == 2) {
			int l = 0, r = col_prefs[col].size() - 1, valid = -1;

			while (l <= r) {
				int mid = (l + r) / 2;
				ll initVal = col_prefs[col][mid];
				ll toAdd = (tot - col_exclude[col]) * mid;

				if (initVal + toAdd <= arg) valid = mid, l = mid + 1;
				else r = mid - 1;
			}

			cout << valid << el;
		}
	}

	return 0;
}
