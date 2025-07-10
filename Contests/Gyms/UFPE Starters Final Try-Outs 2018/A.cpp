#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MOD = 1e9+7;
	string s, w;	cin >> s >> w;
	int n = (int)s.size(), m = (int)w.size();

	vector<int> dp(m + 1, 0);
	dp[0] = 1;
	for (char &c: s) {
		for (int j = m - 1; j >= 0; --j) if (c == w[j]) {
			dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
		}
	}

	return cout << dp[m], 0;
}

