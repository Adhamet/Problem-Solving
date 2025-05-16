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

		for (int steps=0; steps<=9; ++steps) {
			string s = to_string(n-steps);
			int num = 0;
			for (auto &c: s) if (c <= '7') {
				num = max(num, c - '0');
			}

			if (steps >= 7 - num) {
				cout << steps << el;
				break;
			}
		}
	}

	return 0;
}
