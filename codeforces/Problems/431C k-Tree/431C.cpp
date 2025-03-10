#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MOD = 1000000007, MAXN = 105;
int64_t n, k, d;
int64_t memo[MAXN][2];

int64_t recurse(int64_t sum, int32_t found) {
	if (sum > n) return 0;
	if (sum == n) return found == 1;
	
	int64_t &ret = memo[sum][found];
	if (~ret) return ret;
	ret = 0;
	
	for (int i = 1; i <= k; ++i) {
		if (i >= d) ret = (ret + recurse(sum + i, 1)) % MOD;
		else ret = (ret + recurse(sum + i, found)) % MOD;
	}

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k >> d;
	memset(memo, -1, sizeof memo);
	return cout << recurse(0, 0), 0;
}
