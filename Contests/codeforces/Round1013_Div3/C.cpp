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
		if (n % 2 == 0) cout << -1 << el;
		else {
			vector<int> perm(n);
			int idx = 0, num = 1;
			for (; num <= n; idx++) perm[idx] = num, num+=2;
			num = 2;
			for (; num <= n - 1; idx++) perm[idx] = num, num+=2;
			for (int i = 0; i < n; ++i) cout << perm[i] << ' ';
			cout << el;
		}
	}

	return 0;
}
