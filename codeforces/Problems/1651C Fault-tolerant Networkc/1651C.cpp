#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<i64> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int j = 0; j < n; ++j) cin >> b[j];

		i64 minA1 = LLONG_MAX, minA2 = LLONG_MAX;
		i64 minB1 = LLONG_MAX, minB2 = LLONG_MAX;
		for (int i = 0; i < n; ++i) {
			minA1 = min(minA1, abs(a[0] - b[i]));
			minA2 = min(minA2, abs(a[n - 1] - b[i]));
			minB1 = min(minB1, abs(b[0] - a[i]));
			minB2 = min(minB2, abs(b[n - 1] - a[i]));
		}

		i64 op1 = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
		i64 op2 = abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]);
		i64 op3 = abs(a[0] - b[0]) + minA2 + minB2;
		i64 op4 = abs(a[n - 1] - b[0]) + minA1 + minB2;
		i64 op5 = abs(a[0] - b[n - 1]) + minA2 + minB1;
		i64 op6 = abs(a[n - 1] - b[n - 1]) + minA1 + minB1;
		i64 op7 = minA1 + minA2 + minB1 + minB2;
		cout << min({op1, op2, op3, op4, op5, op6, op7}) << el;
	}

	return 0;
}

