#include <bits/stdc++.h>
using namespace std;
#define fst first
#define scd second
#define el '\n'

const int32_t MX1 = 105, MX2 = 10005;
pair<int32_t, int32_t> a[MX1];
int32_t n, m, k, memo[MX1][MX2];

int32_t solve(int32_t idx, int32_t width) {
	if (idx == n) return width;
	int32_t &ret = memo[idx][width];
	if (~ret) return ret;
	ret = solve(idx + 1, width + a[idx].scd);
	if (width >= a[idx].fst)
		ret = min(ret, a[idx].fst + solve(idx + 1, width - a[idx].fst));
	return ret;
}

int32_t main() {
	memset(memo, -1, sizeof memo);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &a[i].scd, &a[i].fst);
	sort(a, a + n);
	reverse(a, a + n);
	return printf("%d", solve(0, 0)), 0;
}
