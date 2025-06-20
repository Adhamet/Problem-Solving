#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MXN = 2005;
vector<i32> a;
int n, memo[MXN][MXN];

int solve(int idx, int pp, int w, int p) {
	if (pp > p) return 1e9;
	if (idx == n) return 0;

	int &ret = memo[idx][pp], j;
	if (~ret) return ret;
	ret = 1e9;

	j = idx;
	while (j < n && a[j] < a[idx] + w) ++j;
	ret = min(ret, solve(j, pp+1, w, p));
	j = idx;
	while (j < n && a[j] < a[idx] + 2 * w) ++j;
	ret = min(ret, 1 + solve(j, pp, w, p));

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int p, q;
	cin >> n >> p >> q;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	int l = 1, r = 1e9, ans = INT_MAX;
	while (l <= r) {
		int md = (l + r) >> 1;
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= p; ++j)
				memo[i][j] = -1;
		if (solve(0,0,md,p) <= q) ans = md, r = md - 1;
		else l = md + 1;
	}

	return cout << ans, 0;
}

