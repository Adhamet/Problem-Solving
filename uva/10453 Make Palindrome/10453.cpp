#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	while (getline(cin, s)) {
		int n = (int)s.size();
		if (n == 0) {
			cout << "0 " << el;
			continue;
		}

		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int len = 2; len <= n; ++len) {
			for (int i = 0; i + len - 1 < n; ++i) {
				int j = i + len - 1;
				if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
				else dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
			}
		}

		int l = 0, r = n - 1;
		string ls = "", rs = "";
		while (l < r) {
			if (s[l] == s[r]) {
				ls += s[l], rs += s[r];
				l++, r--;
			} else if (dp[l+1][r] <= dp[l][r-1]) {
				ls += s[l], rs += s[l];
				l++;
			} else ls += s[r], rs += s[r], --r;
		}

		if (l == r) ls += s[l];
		reverse(rs.begin(), rs.end());
		cout << dp[0][n-1] << ' ' << ls+rs << el;
		cout.flush();
	}

	return 0;
}
