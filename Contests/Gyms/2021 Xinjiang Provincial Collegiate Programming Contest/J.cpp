#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 1e6 + 5;

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> vis(MAXN), freq(MAXN);
	for (int i = 0, x; i < n; ++i) cin >> x, freq[x]++;

	int dp[50], ans = 0;
	for (int i = 1; i < MAXN; ++i) {
		if (freq[i] && !vis[i]) {
			vector<int> cv;
			int x = i;
			while (x < MAXN && freq[x]) {
				cv.push_back(freq[x]);
				vis[x] = 1;
				x *= 2;
			}

			int m = (int)cv.size();
			for (int j = 0; j <= m; ++j) dp[j] = 1e7;
			dp[0] = 0;
			for (int j = 0; j < m; ++j) {
				dp[j + 1] = min(dp[j + 1], dp[j] + cv[j]);
				if (j + 2 <= m) dp[j + 2] = min(dp[j + 2], dp[j] + cv[j + 1]);
			}

			ans += min(dp[m], dp[m - 1]);
		}
	}

	return cout << ans, 0;
}

