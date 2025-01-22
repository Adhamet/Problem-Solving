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
		int n, m, x;
		cin >> n >> m;
		stack<int> stk;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = n - 1; i >= 0; --i) stk.push(a[i]);

		int cnt = 0, ans = 0;
		unordered_map<int, bool> vis;
		for (int i = 0, left = 0, done = 0; i < m; ++i) {
			left = (done - cnt);
			cin >> x;
			if (vis[x]) ans += 1, cnt += 1;
			else {
				while (!stk.empty() && x != stk.top()) {
					left += 1, done += 1;
					vis[stk.top()] = 1, stk.pop();
				}

				if (cnt <= m) ans += ((2 * left) + 1);
				cnt += 1;
			}
		}

		cout << ans << el;
	}
	return 0;
}
