#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> stones(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> stones[i][j];
			}
		}

		auto valid = [&](int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; };

		vector<vector<int>> dp(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0) dp[i][j] = stones[i][j];
				else {
					if (valid(i-1, j-1)) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + stones[i][j]);
					if (valid(i-1, j)) dp[i][j] = max(dp[i][j], dp[i-1][j] + stones[i][j]);
					if (valid(i-1, j+1)) dp[i][j] = max(dp[i][j], dp[i-1][j+1] + stones[i][j]);
				}
			}
		}

		int mxAns = 0;
		for (int j = 0; j < m; ++j) mxAns = max(mxAns, dp[n - 1][j]);
		cout << mxAns << el;
	}

	return 0;
}
