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
		string s, t;
		cin >> s;

		int n = (int)s.size();
		vector<vector<int>> dp(6102, vector<int>(6102));
		for (int l = n - 1; l >= 0; --l)
			for (int r = l; r < n; ++r) 
				if (s[l] == s[r]) dp[l][r] = dp[l+1][r-1];
				else dp[l][r] = min(1+dp[l+1][r], 1+dp[l][r-1]);
		cout << dp[0][n-1] << el;
	}

	return 0;
}
