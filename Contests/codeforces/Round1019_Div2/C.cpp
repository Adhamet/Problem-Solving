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
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<int> pre(n + 1), suff(n + 1);
		for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + (a[i - 1] <= k);
		for (int i = n - 1; i >= 0; --i) suff[i] = suff[i + 1] + (a[i] <= k);

		bool op1 = 0;
		for (int l = 1; l <= n - 2; ++l) {
			int req = (l + 1) / 2;
			if (pre[l] >= req && pre[n] - pre[l + 1] >= 1) {
				op1 = 1;
				break;
			}
		}


		bool op2 = 0, op3 = 0;
		vector<bool> vl(n + 1), pvl(n + 1);
		for (int l = 1; l <= n; ++l) vl[l] = (pre[l] >= (l + 1) / 2);
		for (int i = 1; i <= n; ++i) pvl[i] = pvl[i - 1] || vl[i];
		for (int r = 1; r <= n - 2; ++r) {
			int len = n - r - 1, req = (len + 1) / 2;
			if (suff[r + 1] >= req && pvl[r - 1]) {
				op2 = 1;
				break;
			}
		}
		for (int r = 1; r <= n - 2; ++r) {
			int len = n - r - 1, req = (len + 1) / 2;
			if (suff[r + 1] >= req && a[r] <= k) {
				op3 = 1;
				break;
			}
		}

		cout << ((op1 || op2 || op3)? "YES" : "NO") << el;
	}

	return 0;
}

