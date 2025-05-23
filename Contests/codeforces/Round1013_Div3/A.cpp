#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		map<int, int> dt = {
			{0, 3},
			{1, 1},
			{3, 1},
			{2, 2},
			{5, 1},
		};

		int n; cin >> n;
		int cnt = 0;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			if (dt[x]) {
				cnt += 1;
				dt[x] -= 1;
				if (cnt == 8)
					cout << i + 1 << el;
			}
		}

		if (cnt != 8) cout << 0 << el;
	}

	return 0;
}
