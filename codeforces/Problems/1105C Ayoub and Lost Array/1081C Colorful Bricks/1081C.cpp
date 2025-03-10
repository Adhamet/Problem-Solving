#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int32_t MAXN = 2005, MOD = 998244353;
int32_t n, m, k;
int64_t memo[MAXN][MAXN];

int64_t recurse(int32_t idx, int32_t currk) {
	if (idx >= n) return (currk == k);

	int64_t &ret = memo[idx][currk];
	if (~ret) return ret;
	ret = 0;

	int64_t ways1 = (recurse(idx + 1, currk)) % MOD;
	int64_t ways2 = 0;
	if (currk < k) ways2 = (m - 1) * (recurse(idx + 1, currk + 1) % MOD) % MOD;
	return ret = (ways1+ways2) % MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d %d %d", &n, &m, &k);

	memset(memo, -1, sizeof memo);

	int64_t ans = (m * recurse(1, 0)) % MOD;
	return printf("%ld", ans), 0;
}
