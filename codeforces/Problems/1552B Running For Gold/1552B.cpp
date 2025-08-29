#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;

		vector<vector<int>> a(n, vector<int>(5));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 5; ++j)
				cin >> a[i][j];
		
		int cand = 0;
		for (int i = 1; i < n; ++i) {
			int cnt = 0;
			for (int j = 0; j < 5; ++j)
				if (a[i][j] < a[cand][j]) cnt++;
			if (cnt >= 3) cand = i;
		}

		bool acc = true;
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			for (int j = 0; j < 5; ++j) if (a[i][j] < a[cand][j]) cnt++;
			if (cnt >= 3) {
				acc = false;
				break;
			}
		}

		cout << (acc? cand + 1: -1) << '\n';
	}

	return 0;
}

