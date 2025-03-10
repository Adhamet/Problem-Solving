#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 2e5+5, MOD = 1e9+7;
int64_t n, l, r, numsOf0, numsOf1, numsOf2;
int64_t memo[MAXN][3];

int64_t recurse(int32_t idx, int64_t remSum) {
	if (idx > n) return (remSum == 0);

	int64_t &ret = memo[idx][remSum];
	if (~ret) return ret;
	ret = 0;

	int64_t ways0 = (recurse(idx + 1, remSum) * numsOf0) % MOD;
	int64_t ways1 = (recurse(idx + 1, (remSum + 1) % 3) * numsOf1) % MOD;
	int64_t ways2 = (recurse(idx + 1, (remSum + 2) % 3) * numsOf2) % MOD;
	return ret = (ways0+ways1+ways2) % MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%ld %ld %ld", &n, &l, &r);
	numsOf0 = (r / 3) - ((l - 1) / 3);
	numsOf1 = ((r + 1) / 3) - (l / 3);
	numsOf2 = ((r + 2) / 3) - ((l + 1) / 3);

	memset(memo, -1, sizeof memo);
	return printf("%ld", recurse(1, 0)), 0;
}
