#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int32_t MAXN = 504, oo = 1e9+7;
int32_t n, memo[MAXN][MAXN][MAXN], a[MAXN];

int32_t recurse(int32_t idx, int32_t x, int32_t last) {
	if (idx > n) return 0;

	int32_t &ret = memo[idx][x][last];
	if (~ret) return ret;
	ret = oo;

	if (a[idx] >= last) ret = min(ret, recurse(idx+1, x, a[idx]));
	if (x >= last && a[idx] > x) ret = min(ret, 1 + recurse(idx+1, a[idx], x));
	return ret;
}

int32_t main() {
	int32_t _tc, x;
	scanf("%d", &_tc);

	while (_tc--) {
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= 500; ++j)
				for (int k = 0; k <= 500; ++k)
					memo[i][j][k] = -1;
		
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		int32_t res = recurse(1, x, 0);
		printf("%d\n", (res == oo? -1: res));
	}

	return 0;
}
