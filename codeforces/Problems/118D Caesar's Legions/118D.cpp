#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int64_t MAXN = 105, MOD = 100000000;
int32_t k1, k2;
int64_t memo[MAXN][MAXN][2];

int64_t solve(int32_t leftN1, int32_t leftN2, int32_t last) {
	if (leftN1 == 0 && leftN2 == 0) return 1;

	int64_t &ret = memo[leftN1][leftN2][last];
	if (~ret) return ret;
	ret = 0;

	if (last == 0) {
		for (int i = 1; i <= min(leftN2, k2); ++i)
			ret = (ret + solve(leftN1, leftN2 - i, 1)) % MOD;
	} else if (last == 1) {
		for (int i = 1; i <= min(leftN1, k1); ++i)
			ret = (ret + solve(leftN1 - i, leftN2, 0)) % MOD;
	}

	return ret;
}

int32_t main() {
	int32_t n1, n2;
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	for (int i = 0; i <= n1; ++i)
		for (int j = 0; j <= n2; ++j)
			for (int k = 0; k < 2; ++k)
				memo[i][j][k] = -1;
	return printf("%lld", (solve(n1, n2, 0) + solve(n1, n2, 1)) % MOD), 0;
}
