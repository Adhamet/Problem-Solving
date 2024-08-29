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

	ll t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		vector<vector<int>> pref(n + 1, vector<int>(31));
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < 31; j++) {
				pref[i + 1][j] = pref[i][j];
				if (a[i] & (1 << j)) pref[i + 1][j] += 1;
			}
		}

		int q;
		cin >> q;

		vector<int> results;
		while (q--) {
			int l, k;
			cin >> l >> k;
			if (a[l - 1] < k) {
				results.push_back(-1);
				continue;
			}

			int lf = l, rt = n, ans = lf;
			while (lf <= rt) {
				int mid = (lf + rt) / 2;

				int num = 0;
				for (int j = 0; j < 31; j++) {
					if (pref[mid][j] - pref[l - 1][j] == mid - l + 1) {
						num += (1 << j);
					}
				}

				if (num >= k) lf = mid + 1, ans = max(ans, mid);
				else rt = mid - 1;
			}
			results.push_back(ans);
		}

		for (auto res: results) cout << res << " ";
		cout << el;
	}

	return 0;
}
