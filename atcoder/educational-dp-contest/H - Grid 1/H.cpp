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

	queue<array<int, 2>> q;
	q.push({0, 0});
	dp[0][0] = 1;

	while (!q.empty()) {
		int x = q.front()[0], y = q.front()[1];
		q.pop();

		if (valid(x + 1, y) && grid[x + 1][y] != '#') {
			if (dp[x + 1][y] == 0) q.push({x + 1, y});
			dp[x + 1][y] = (dp[x + 1][y] + dp[x][y]) % mod;
		}

		if (valid(x, y + 1) && grid[x][y + 1] != '#') {
			if (dp[x][y + 1] == 0) q.push({x, y + 1});
			dp[x][y + 1] = (dp[x][y + 1] + dp[x][y]) % mod;
		}
	}

	return cout << dp[n - 1][m - 1], 0;
}
