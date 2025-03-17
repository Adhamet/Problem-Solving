#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int32_t MAXN = 202;
int32_t rn, gn, bn;
int64_t rarr[MAXN], garr[MAXN], barr[MAXN], memo[MAXN][MAXN][MAXN];

int64_t solve(int32_t ridx, int32_t gidx, int32_t bidx) {
	if ((ridx >= rn && gidx >= gn) || (ridx >= rn && bidx >= bn) || (gidx >= gn && bidx >= bn))
		return 0;

	int64_t &ret = memo[ridx][gidx][bidx];
	if (~ret) return ret;
	ret = 0;

	if (ridx < rn && gidx < gn)
		ret = max(ret, (rarr[ridx] * garr[gidx]) + solve(ridx+1, gidx+1, bidx));
	if (ridx < rn && bidx < bn)
		ret = max(ret, (rarr[ridx] * barr[bidx]) + solve(ridx+1, gidx, bidx+1));
	if (gidx < gn && bidx < bn)	
		ret = max(ret, (garr[gidx] * barr[bidx]) + solve(ridx, gidx+1, bidx+1));

	return ret;
}

int32_t main() {
	scanf("%d %d %d", &rn, &gn, &bn);
	for (int i = 0; i < rn; ++i) scanf("%lld", &rarr[i]);
	for (int i = 0; i < gn; ++i) scanf("%lld", &garr[i]);
	for (int i = 0; i < bn; ++i) scanf("%lld", &barr[i]);
	sort(rarr, rarr + rn, greater<int>());
	sort(garr, garr + gn, greater<int>());
	sort(barr, barr + bn, greater<int>());
	for (int i = 0; i <= rn; ++i)
		for (int j = 0; j <= gn; ++j)
			for (int k = 0; k <= bn; ++k)
				memo[i][j][k] = -1;
	return printf("%lld", solve(0, 0, 0)), 0;
}
