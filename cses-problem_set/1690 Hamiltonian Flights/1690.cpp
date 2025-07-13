#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	constexpr int M = 1e9+7;

	int n, m;	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
	}

	int N = (1<<n) - 1;
	vector<vector<int>> dp(1<<n, vector<int>(n, 0));
	dp[1<<0][0] = 1;
	for (int msk = 1; msk <= N; ++msk) {
		if (!(msk & 1)) continue;

		for (int sub = msk; sub; sub &= sub-1) {
			int v = __builtin_ctz(sub);
			if (!dp[msk][v]) continue;
			for (int &vv: g[v]) {
				if (msk & (1<<vv)) continue;
				int nxt = msk | (1<<vv);
				dp[nxt][vv] = (dp[nxt][vv] + dp[msk][v]) % M;
			}
		}
	}

	return cout << dp[N][n-1], 0;
}

