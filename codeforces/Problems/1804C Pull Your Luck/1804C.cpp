#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		i64 n, x, p;
		cin >> n >> x >> p;

		bool acc = false;
		for (i64 f = 1; f <= min(p, 2*n); ++f) {
			i64 sm = f * (f + 1) / 2;
			if ((sm + x) % n == 0) {
				acc = true;
				break;
			}
		}

		cout << (acc? "Yes": "No") << '\n';
	}

	return 0;
}

