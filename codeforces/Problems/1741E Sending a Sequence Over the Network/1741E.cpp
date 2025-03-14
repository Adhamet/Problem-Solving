#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	int32_t tc;
	scanf("%d", &tc);

	while (tc--) {
		int32_t n;
		scanf("%d", &n);

		vector<int32_t> a(n + 1);
		for (int i = 1; i <= n; ++i) cin >> a[i];

		vector<int32_t> dp(n + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= n; ++i) {
			if (dp[i - 1] == 1 && (i + a[i]) <= n) dp[i + a[i]] = 1;
			if ((i - a[i] - 1) >= 0 && dp[i - a[i] - 1] == 1) dp[i] = 1;
		}

		printf("%s\n", (dp[n] == 1 ? "YES" : "NO"));
	}

	return 0;
}
