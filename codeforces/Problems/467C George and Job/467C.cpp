#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int64_t MAXN = 5003;
int32_t n, m;
int64_t memo[MAXN][MAXN], pref[MAXN];

int64_t solve(int32_t l, int32_t k) {
    if (k == 0) return 0;
    if (l + m > n) return LLONG_MIN;
    int64_t &ret = memo[k][l];
    if (~ret) return ret;
    ret = solve(l + 1, k);
    ret = max(ret, (pref[l + m] - pref[l]) + solve(l + m, k - 1));
    return ret;
}

int32_t main() {
    int32_t k;
    scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= k; ++i)
		for (int j = 0; j < n; ++j)
			memo[i][j] = -1;
    int64_t a[n];
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) pref[i] = a[i - 1] + pref[i - 1];
    return printf("%lld", solve(0, k)), 0;
}

