#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int n, m;
bool valid(int r, int c) {
	return r >= 0 && r < 2 && c >= 0 && c < m;
}

const int dr[] = {1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> dp(2, vector<int>(m));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < m; ++j) {
			if (valid(i + 1, j)) dp[i + 1][j] = dp[i][j] + 1;
			if (valid(i, j + 1)) dp[i][j + 1] = dp[i][j] + 1;
			if (valid(i + 1, j + 1)) dp[i + 1][j + 1] = dp[i][j] + 1;
			if (valid(i - 1, j)) dp[i - 1][j] = dp[i][j] + 1;
			if (valid(i - 1, j + 1)) dp[i - 1][j + 1] = dp[i][j] + 1;
		}
	}

	int mx = max(dp[1][m - 1], dp[0][m - 1]);
	mx *= 2;
	mx += (n - 2) / 2;
	return cout << mx << el, 0;
}
