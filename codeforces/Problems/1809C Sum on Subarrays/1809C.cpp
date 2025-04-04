#include <bits/stdc++.h>
using namespace std;
#define el '\n'

vector<int32_t> dp[31][500];
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	dp[1][0] = (vector<int32_t>){1, 0};
	dp[1][1] = (vector<int32_t>){0, 1};
	for (int n = 2; n <= 30; ++n) {
		for (int k = 0; k <= n * (n + 1) / 2; ++k) {
			for (int t = 0; t <= n; ++t) {
				if (k >= t && !dp[n - 1][k - t].empty()) {
					dp[n][k] = dp[n - 1][k - t];
					dp[n][k].insert(dp[n][k].begin() + t, n);
					break;
				}
			}
		}
	}

	int32_t tc;
	cin >> tc;
	while (tc--) {
		int32_t n, k;
		cin >> n >> k;
		
		vector<int32_t> ans = dp[n][k];
		vector<int32_t> A(n + 1, 0);

		int idx = 0;
		while (ans[idx] != 0) ++idx;
		for (int i = idx + 1; i < (int32_t)ans.size(); ++i) A[ans[i]] = i - idx;
		for (int i = idx - 1; i >= 0; --i) A[ans[i]] = i - idx;
		for (int i = 1; i <= n; ++i) cout << A[i] - A[i - 1] << (i == n? el: ' ');
	}

	return 0;
}
