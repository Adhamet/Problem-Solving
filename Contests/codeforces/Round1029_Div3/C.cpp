#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		set<int> prevSt, currSt;
		unordered_set<int> vis;
		prevSt.insert(a[0]);

		int found = 0, ans = 1;
		for (int i = 1; i < n; ++i) {
			if (found == (int)prevSt.size()) {
				ans += 1;
				found = 0;
				vis.clear();
				prevSt = currSt;
			}

			if (prevSt.count(a[i]) && !vis.count(a[i])) {
				vis.insert(a[i]);
				found += 1;
			} 

			currSt.insert(a[i]);
		}

		if (found == (int)prevSt.size()) {
			ans += 1;
			found = 0;
			vis.clear();
			prevSt = currSt;
		}
		cout << ans << el;
	}

	return 0;
}

