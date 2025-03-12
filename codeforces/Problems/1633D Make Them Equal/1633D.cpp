#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 1002, oo = 1e9+7;
int32_t n, k;
int64_t kmemo[MAXN], b[MAXN], c[MAXN];
int64_t memo[MAXN][12 * MAXN];

int64_t recurse(int32_t idx, int32_t ops) {
	if (idx >= n) return 0;

	int64_t &ret = memo[idx][ops];
	if (~ret) return ret;

	ret = recurse(idx + 1, ops); // leave
	if (ops >= kmemo[b[idx]]) // pick
		ret = max(ret, recurse(idx + 1, ops - kmemo[b[idx]]) + c[idx]);
	return ret;
}

int32_t main() {
	memset(kmemo, oo, sizeof kmemo);
	kmemo[1] = 0;

	for (int i = 1; i < MAXN; ++i) {
		for (int j = 1; j <= i; ++j) {
			int64_t val = i + (i / j);
			if (val < MAXN) kmemo[val] = min(kmemo[val], kmemo[i] + 1);
		}
	}

	int32_t _tc;
	scanf("%d", &_tc);

	while (_tc--) {
		memset(memo, -1, sizeof memo);

		scanf("%d %d", &n, &k);
		k = min(k, 12 * n);

		for (int i = 0; i < n; ++i) scanf("%ld", &b[i]);
		for (int i = 0; i < n; ++i) scanf("%ld", &c[i]);

		printf("%ld\n", recurse(0, k));
	}

	return 0;
}
