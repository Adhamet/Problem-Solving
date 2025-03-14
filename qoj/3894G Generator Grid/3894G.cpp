#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int64_t MAXN = 2e5+5, oo = 1e18+2;
unordered_map<int32_t, int64_t> pp;
int64_t n, m, pl[MAXN];
int64_t memo[MAXN][2][2][2]; // idx, hasPP, lastPP, powered

int64_t solve(int32_t idx, int32_t is, int32_t last, int32_t pw) {
	if (idx == n) return pw? 0: oo;

	int64_t &ret = memo[idx][is][last][pw];
	if (~ret) return ret;
	ret = oo;

	// if can build pp build pp.
	if (pp.count(idx))
		ret = min(ret, pp[idx] + solve(idx+1, true, last || is, 1));
	// build prev pl
	if (is && idx > 0)
		ret = min(ret, pl[idx - 1] + solve(idx+1, true, last, pw));
	// build next pl
	if (idx < n)
		ret = min(ret, pl[idx] + solve(idx + 1, false, last, pw));
	return ret;
}

int32_t main() {
	memset(memo, -1, sizeof memo);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int32_t u;
		int64_t w;
		scanf("%d %lld", &u, &w);
		pp[u - 1] = w;
	}

	for (int i = 0; i < n; ++i) cin >> pl[i];
	return printf("%lld", solve(0, 0, 0, 0)), 0;
}
