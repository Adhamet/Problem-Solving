#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, mxR = 0;
		cin >> n;
		vector<array<int, 2>> segs(n);
		for (int i = 0; i < n; ++i) {
			cin >> segs[i][0] >> segs[i][1];
			mxR = max(mxR, segs[i][1]);		
		}

		auto can = [&](int k) -> bool {
			int ll = 0, rr = 0;
			for (auto seg: segs) {
				ll = max(ll - k, seg[0]);
				rr = min(rr + k, seg[1]);
				if (ll > rr) return false;
			}
			return true;
		};

		int l = 0, r = mxR, ans = mxR;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (can(mid)) r = mid - 1, ans = mid;
			else l = mid + 1;
		}

		cout << ans << el;
	}

	return 0;
}

