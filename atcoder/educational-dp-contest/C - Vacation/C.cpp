#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> input(n, vector<int>(3));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> input[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(3));
	for (int i = 0; i < n; ++i) dp[0][i] = input[0][i];
	for (int i = 1; i < n; ++i) {
		dp[i][0] = input[i][0] + max({dp[i - 1][1], dp[i - 1][2]});
		dp[i][1] = input[i][1] + max({dp[i - 1][0], dp[i - 1][2]});
		dp[i][2] = input[i][2] + max({dp[i - 1][0], dp[i - 1][1]});
	}

	return cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}), 0;
}
