#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = (int)s.size(), m = (int)t.size();

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int i = n, j = m;
	string lcs = "";
	while (i > 0 && j > 0) {
		if (s[i - 1] == t[j - 1]) lcs += s[i - 1], i -= 1, j -= 1;
		else if (dp[i - 1][j] > dp[i][j - 1]) i -= 1;
		else j -= 1;
	}

	reverse(lcs.begin(), lcs.end());
	return cout << lcs, 0;
}
