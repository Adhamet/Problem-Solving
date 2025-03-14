#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int32_t MAXN = 2e5+5, MOD = 1e9+7;
int64_t k, memo[MAXN];

int64_t solve(int32_t idx) {
	if (idx == 0) return 1;
	if (memo[idx]) return memo[idx];
	memo[idx] = (memo[idx] + solve(idx - 1)) % MOD;
	if (idx - k >= 0) memo[idx] = (memo[idx] + solve(idx - k)) % MOD;
	return memo[idx];
}

int32_t main() {
	memset(memo, 0, sizeof memo);

	int32_t tc;
	scanf("%d %lld", &tc, &k);

	for (int32_t i = 1; i <= 100000; ++i) solve(i);
	for (int32_t i = 1; i <= 100000; ++i) memo[i] += memo[i - 1];
	
	while (tc--) {
		int32_t a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", (memo[b] - memo[a - 1] + MOD) % MOD);
	}

	return 0;
}
