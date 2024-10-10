#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'
#define int long long

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, tc, tm;
		cin >> n >> tc >> tm;

		vector<int> a(n), b(n), c(n), need(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			need[i] = max(0ll, (a[i] * tc) + (b[i] * tm) - c[i]);
		}

		function<bool(int)> check = [&](int mid) {
			int mnx = 0, mny = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] > b[i]) {
					mnx = max(mnx, (((need[i] - (mid * b[i])) + (a[i] - b[i] - 1)) / (a[i] - b[i])));
				} else if (a[i] < b[i]) {
					mny = max(mny, (((need[i] - (mid * a[i])) + (b[i] - a[i] - 1)) / (b[i] - a[i])));
				} else {
					if (a[i] * mid < need[i]) return false;
				}
			}

			if (mnx >= tc || mny >= tm || mnx + mny > mid) return false;
			return true;
		};
		
		int l = 0, r = INT_MAX, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;

			if (check(mid)) r = mid - 1, ans = mid;
			else l = mid + 1;
		}

		cout << ans << el;
	}

	return 0;
}
