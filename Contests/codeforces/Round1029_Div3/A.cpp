#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int fst = -1, last = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 1) {
				if (fst == -1) fst = i;
				last = i;
			}
		}

		if (last - fst + 1 <= k) cout << "YES" << el;
		else cout << "NO" << el;
	}

	return 0;
}
