#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int mod = 1e9+7;
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	auto valid = [&](int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; };

	vector<vector<char>> grid(n, vector<char>(m));
	vector<vector<int>> dp(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '#') continue;
			if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
		}
	}

	return cout << dp[n - 1][m - 1], 0;
}

