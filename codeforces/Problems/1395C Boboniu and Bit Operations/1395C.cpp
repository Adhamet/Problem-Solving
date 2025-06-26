#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int j = 0; j < m; ++j) cin >> b[j];

	for (int msk = 0; msk < (1 << 9); ++msk) {
		bool acc = true;
		for (int i = 0; i < n; ++i) {
			bool found = false;
			for (int j = 0; j < m; ++j) {
				if (((a[i] & b[j]) | msk) == msk) {
					found = true;
					break;
				}
			}

			if (!found) acc = false;
		}

		if (acc) return cout << msk, 0;
	} return 0;
}
