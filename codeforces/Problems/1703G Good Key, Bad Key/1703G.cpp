#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 1e5+5;
int64_t n, k, memo[MAXN][33]; // idx, halves
vector<int64_t> a;

int64_t solve(int32_t idx, int64_t halves) {
	if (idx == n || halves >= 32) return 0;

	int64_t &ret = memo[idx][halves];
	if (~ret) return ret;

	ret = solve(idx + 1, halves) + ((a[idx] >> halves) - k);
	if (halves < 32) // at h>=32 coins become 0
		ret = max(ret, solve(idx + 1, halves + 1) + (a[idx] >> (halves + 1)));
	return ret;
}

int32_t main() {
	int32_t tc;
	scanf("%d", &tc);
	
	while (tc--) {
		scanf("%lld %lld", &n, &k);
		a.assign(n, 0);
		for (int i = 0; i < n; ++i) cin >> a[i];

		for (int i = 0; i <= n; ++i) 
			for (int j = 0; j < 33; ++j)
				memo[i][j] = -1;
		printf("%lld\n", solve(0, 0));
	}

	return 0;
}
