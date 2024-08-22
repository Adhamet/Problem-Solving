#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<ll> a(n), pref(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];

			pref[i + 1] = pref[i] + a[i];
		}

		vector<bool> acc(n);
		for (int i = 0; i < n; i++) {
			if ((a[i] % 2 == 0 && a[i + 1] % 2 == 1) || (a[i] % 2 == 1 && a[i + 1] % 2 == 0)) {
				acc[i] = true;
				acc[i + 1] = true;
			} else if (i == n - 1) acc[i] = false;
		}

		int l = 0, r = 0;
		vector<pair<int, int>> prs;
		while (l < n) {
			while (r < n && acc[r] == 1) r += 1;

			if (r - l >= 1) prs.push_back(make_pair(l, r - 1)), l = r - 1;
			l += 1, r = l;
		}

		ll ans = 0;
		for (auto pr: prs) {
			ll currMaxSubArrSum = pref[pr.first + 1] - pref[pr.first];
			ll currMin = 0;

			l = pr.first + 2, r = pr.second + 1;
			while (l <= r) {
				ll currPref = pref[l] - pref[pr.first];
				currMaxSubArrSum = max(currMaxSubArrSum, currPref - currMin);
				currMin = min(currMin, currPref);
				l++;
			}

			ans = max(ans, currMaxSubArrSum);
		}
		cout << ans << el;
	}

	return 0;
}
