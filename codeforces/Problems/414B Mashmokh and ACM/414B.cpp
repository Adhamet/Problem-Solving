#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	const int MOD = 1e9 + 7, MXN = 2005;
	int n, k; cin >> n >> k;

	static i64 memo[MXN][MXN];
	for (int i = 0; i < MXN; ++i)
		for (int j = 0; j < MXN; ++j)
			memo[i][j] = -1;

	function<i64(int,int)> solve = [&](int idx, int x) -> i64 {
		if (idx == k) return 1;
		
		i64 &ret = memo[idx][x];
		if (~ret) return ret;
		ret = 0;

		for (int m = x; m <= n; m += x) 
			ret = (ret + solve(idx + 1, m)) % MOD;
		return ret;
	}; 

	i64 ans = 0;
	for (int x = 1; x <= n; ++x) ans = (ans + solve(1, x)) % MOD;
	return cout << ans, 0;
}
