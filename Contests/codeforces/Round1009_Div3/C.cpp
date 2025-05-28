#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int x; cin >> x;

		if (!(x & (x-1)) || !((x+1) & x)) {
			cout << -1 << el;
			continue;
		}

		int m = (1 << (31 - __builtin_clz(x)));
		cout << m - 1 << el;
	}

	return 0;
}
