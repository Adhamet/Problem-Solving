#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<vector<int>> dp(n, vector<int>(2, 1));
	int ans = 1;
	
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (abs(a[j]) < abs(a[i])) {
				if (a[i] > 0 && a[j] < 0) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
				if (a[i] < 0 && a[j] > 0) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
			}
		}

		ans = max({ans, dp[i][0], dp[i][1]});
	}

	return 0;
}	
