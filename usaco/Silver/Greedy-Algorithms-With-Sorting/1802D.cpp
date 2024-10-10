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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<array<int, 2>> vec(n);
		for (auto &i: vec) cin >> i[0] >> i[1];
		sort(vec.begin(), vec.end(), [&](array<int, 2> a, array<int, 2> b) {
			return (a[1] > b[1] || (a[1] > b[1] && a[0] < b[0]));
		});

		multiset<int> a;
		for (int i = 0; i < n; i++) a.insert(vec[i][0]);

		int a_mx = -1, ans = 1e9;
		for (int i = 1; i < n; i++) ans = min(ans, abs(vec[i][0] - vec[0][1]));
		for (int i = 0; i < n; i++) {
			a.erase(a.find(vec[i][0]));
			if (i == 0) {
				a_mx = vec[i][0];
				continue;
			}

			int b_mx = vec[i][1];
			ans = min(ans, abs(a_mx - b_mx));

			auto itr = a.lower_bound(b_mx);
			if (itr != a.end() && *itr > a_mx) ans = min(ans, abs(*itr - b_mx));
			if (itr != a.begin() && *prev(itr) > a_mx) ans = min(ans, abs(*prev(itr) - b_mx));
			a_mx = max(a_mx, vec[i][0]);
		}
		cout << ans << el;
	}

	return 0;
}
