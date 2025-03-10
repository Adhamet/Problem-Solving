#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	int32_t n = (int32_t)s.size();
	int32_t dp[3][n + 1];
	dp[0][0] = dp[1][0] = dp[2][0] = 0;

	for (int i = 0; i < n; ++i) {
		dp[0][i + 1] = dp[0][i] + (s[i] == 'a');
		dp[1][i + 1] = max(dp[0][i], dp[1][i]) + (s[i] == 'b');
		dp[2][i + 1] = max(dp[1][i], dp[2][i]) + (s[i] == 'a');
	}

	return printf("%d", max({dp[0][n], dp[1][n], dp[2][n]})), 0;
}
