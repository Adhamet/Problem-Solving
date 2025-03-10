#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MOD = 998244353;
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int32_t n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int64_t dp[n][k + 1];
	memset(dp, 0, sizeof dp);

	dp[0][0] = m;
	for (int idx = 1; idx < n; ++idx) {
		for (int currk = 0; currk <= k; ++currk) {
			dp[idx][currk] = dp[idx - 1][currk];
			if (currk > 0)
				dp[idx][currk] = (dp[idx][currk] + dp[idx - 1][currk - 1] * (m - 1)) % MOD;
		}
	}

	return printf("%ld", dp[n - 1][k]), 0;
}
